from machine import Pin, ADC
from umqtt.simple import MQTTClient
import network, ntptime, ujson, time

# ---------- Identidade (contrato de evento) ----------
NODE_ID = "esp32-07"
ASSET_ID = "motor-linha3-02"

PREFIXO = "ubiq/swifties/motor-linha3-02"
TOPICO_EVENTOS = PREFIXO + "/eventos"

BROKER = "broker.hivemq.com"
PORTA = 1883

# ---------- Parametros ----------
INTERVALO_EVENTO = 500 # ms
TIMEOUT_ACK = 4000 # 4 segundos
BUFFER_MAX = 100
ADC_MIN, ADC_MAX = 0, 4095 # Intervalo da leitura analógica
VALOR_MAX = 4.0 # Valor máximo da leitura normalizada
UNIDADE = "xRMS_base"
DEBOUNCE_MS = 300 # Debouce para voltar o estado anterior controlado pelo botão
VALIDADE_MS = 20000 # Tolerancia de atraso do prototipo

# ---------- M1: I/O ----------
led_r, led_g, led_b = Pin(25, Pin.OUT), Pin(26, Pin.OUT), Pin(27, Pin.OUT)
pot = ADC(Pin(34))
pot.atten(ADC.ATTN_11DB)
btn = Pin(4, Pin.IN, Pin.PULL_UP)

def cor(r, g, b):
    led_r.value(r)
    led_g.value(g)
    led_b.value(b)

# ---------- Estado ----------
buffer = []
seq_atual = 0
max_confirmado = 0
ok = dup = reenvios = descartados = invalidos = desconhecidos = expirados = 0
cliente = None
online = False
falha_simulada = False
ultima_invalida = False
btn_anterior = 1
t_btn = 0

# ---------- M2: rede e relogio ----------
def conectar_wifi():
    wlan = network.WLAN(network.STA_IF)
    wlan.active(True)
    if not wlan.isconnected():
        wlan.connect("Wokwi-GUEST", "")
        while not wlan.isconnected():
            time.sleep_ms(200)
    print("[WIFI] ok", wlan.ifconfig()[0])

def agora_iso():
    t = time.gmtime(time.time())
    return "%04d-%02d-%02dT%02d:%02d:%02dZ" % (t[0], t[1], t[2], t[3], t[4], t[5])

def estado_link():
    if not online:
        return "OFFLINE"
    if len(buffer) >= BUFFER_MAX:
        return "BUFFER_CHEIO"
    if buffer:
        return "PENDENTE"
    return "EM_DIA"

# ---------- M4: eco recebido = confirmacao ----------
def ao_receber(topico, payload):
    global ok, dup, desconhecidos, max_confirmado
    if falha_simulada:
        return
    try:
        e = ujson.loads(payload)
    except Exception:
        return
    if e.get("deviceId") != NODE_ID:
        return
    seq = e.get("sequence")
    if not isinstance(seq, int):
        return

    for i, ev in enumerate(buffer):
        if ev["seq"] == seq:
            buffer.pop(i)
            ok += 1
            if seq > max_confirmado:
                max_confirmado = seq
            print("[CONFIRMADO] seq=%d  (ok=%d dup=%d reenv=%d perdidos=%d inval=%d exp=%d)"
                  % (seq, ok, dup, reenvios, descartados, invalidos, expirados))
            return

    if seq <= max_confirmado:
        dup += 1
        print("[DUPLICADO] seq=%d descartado por idempotencia (max=%d)"
              % (seq, max_confirmado))
    else:
        desconhecidos += 1
        print("[DESCONHECIDO] seq=%d fora do buffer" % seq)

def conectar_mqtt():
    global cliente
    cliente = MQTTClient(NODE_ID + str(time.ticks_ms() % 9999), BROKER, PORTA)
    cliente.set_callback(ao_receber)
    cliente.connect()
    cliente.subscribe(TOPICO_EVENTOS)
    print("[MQTT] conectado")

# ---------- M3: leitura, validacao e contrato de evento ----------
def gerar_evento():
    global seq_atual, descartados, invalidos, ultima_invalida
    seq_atual += 1

    bruto = pot.read()
    valido = ADC_MIN < bruto < ADC_MAX
    ultima_invalida = not valido

    if len(buffer) >= BUFFER_MAX:
        descartados += 1
        print("[PERDA] seq=%d descartado: buffer cheio" % seq_atual)
        return

    if valido:
        valor, qualidade = round(bruto * VALOR_MAX / ADC_MAX, 2), "VALIDO"
    else:
        invalidos += 1
        valor, qualidade = None, "INVALIDO"
        print("[INVALIDO] seq=%d bruto=%d (saturado ou desconectado)"
              % (seq_atual, bruto))

    buffer.append({
        "seq": seq_atual,
        "t_ms": time.ticks_ms(),
        "ts": agora_iso(),
        "valor": valor,
        "qualidade": qualidade,
        "state": estado_link(),
        "enviado_em": None,
        "tentativas": 0,
        "expirado": False,
    })

# ---------- Adversarial: validade do dado armazenado ----------
def verificar_validade(ev):
    global expirados
    idade = time.ticks_diff(time.ticks_ms(), ev["t_ms"])
    fresco = idade <= VALIDADE_MS
    if not fresco and not ev["expirado"]:
        ev["expirado"] = True
        expirados += 1
        print("[EXPIRADO] seq=%d idade=%d ms > %d ms: historico apenas, sem valor para decisao"
              % (ev["seq"], idade, VALIDADE_MS))
    return idade, fresco

def publicar(ev):
    idade, fresco = verificar_validade(ev)
    msg = ujson.dumps({
        "eventType": "medicao.vibracao",
        "deviceId": NODE_ID,
        "entityId": ASSET_ID,
        "eventTimeMs": ev["t_ms"],
        "eventTimeIso": ev["ts"],
        "sequence": ev["seq"],
        "value": ev["valor"],
        "unit": UNIDADE,
        "quality": ev["qualidade"],
        "state": ev["state"],
        "attempt": ev["tentativas"] + 1,
        "ageMs": idade,
        "freshness": "VALIDO" if fresco else "EXPIRADO",
    })
    cliente.publish(TOPICO_EVENTOS, msg)
    print(msg)
    ev["enviado_em"] = time.ticks_ms()
    ev["tentativas"] += 1

# ---------- M5: store-and-forward ----------
def tratar_pendencias():
    global reenvios
    for ev in buffer:
        nunca = ev["enviado_em"] is None
        expirou = (not nunca and
                   time.ticks_diff(time.ticks_ms(), ev["enviado_em"]) > TIMEOUT_ACK)
        if nunca or expirou:
            if expirou:
                reenvios += 1
                print("[SEM ECO] seq=%d -> reenvio" % ev["seq"])
            publicar(ev)
            return

# ---------- Falha de enlace simulada (botao) ----------
def ler_botao():
    global falha_simulada, btn_anterior, t_btn
    atual = btn.value()
    agora = time.ticks_ms()
    if btn_anterior == 1 and atual == 0 and time.ticks_diff(agora, t_btn) > DEBOUNCE_MS:
        t_btn = agora
        falha_simulada = not falha_simulada
        print("[FALHA SIMULADA] %s" %
              ("enlace cortado" if falha_simulada else "enlace restabelecido"))
    btn_anterior = atual

def atualizar_led():
    if not online:
        cor(1, 0, 0)                        # vermelho: sem enlace
    elif len(buffer) >= BUFFER_MAX:
        cor(0, 0, 1)                        # azul: buffer cheio, ha perda
    elif ultima_invalida:
        cor(1, 0, 1)                        # magenta: leitura invalida
    elif buffer:
        cor(1, 1, 0)                        # amarelo: drenando pendencias
    else:
        cor(0, 1, 0)                        # verde: em dia

# ---------- Principal ----------
cor(0, 0, 1)
conectar_wifi()
ntptime.settime()
print("[NTP]", agora_iso())
conectar_mqtt()

t_evento = time.ticks_ms()

while True:
    ler_botao()
    try:
        cliente.check_msg()
        if falha_simulada:
            online = False
        else:
            online = True
            tratar_pendencias()
    except OSError:
        online = False
        print("[MQTT] caiu, reconectando...")
        try:
            conectar_mqtt()
        except OSError:
            time.sleep_ms(2000)

    if time.ticks_diff(time.ticks_ms(), t_evento) > INTERVALO_EVENTO:
        t_evento = time.ticks_ms()
        gerar_evento()

    atualizar_led()
    time.sleep_ms(50)