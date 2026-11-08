# Relatório — Atividade 03: Protótipo Individual com ESP32 e Wokwi

Link Wokwi: https://wokwi.com/projects/474643797198341121

## 1. Identificação

Sou João Victor Lemes, matrícula 202602614, do grupo Swifties, responsável pelo projeto baseado no produto da Tractian de monitoramento de ativos de fábrica por meio de vibração e temperatura.

## 2. Responsabilidade individual

Minha responsabilidade individual nesta atividade foi a criação de um protótipo focado na comunicação e na resiliência do projeto, isolando a parte do MQTT, que será amplamente utilizada no contexto da atividade e do trabalho final em grupo.

## 3. Relação com o projeto

A parte implementada foi a de comunicação, utilizando principalmente MQTT, com deduplicação, armazenamento e publicação no MQTT por meio do Wi-Fi.

## 4. Fenômeno, entrada, unidade e faixa

No protótipo, foi utilizado um potenciômetro para simular a vibração, ou seja, o valor lido do potenciômetro é contabilizado como se fosse a vibração vinda da máquina. Dessa maneira, é possível ter controle explícito do estado com base na medida de vibração capturada, convertendo a leitura analógica do potenciômetro em uma escala de vibração de 0 a 4.

## 5. Circuito e componentes

O circuito é composto por um ESP32, um potenciômetro, um LED RGB, resistores de 220 ohms e um botão, utilizado para simular quedas de rede e outras situações adversariais.

## 6. Contrato do evento

Os eventos são medidos em tempo real, em um ciclo parametrizável. Neste exemplo, o ciclo foi definido em 500 milissegundos, mas esse valor pode ser alterado.

No JSON publicado, os campos indicam a sequência do evento produzido, o tipo do evento, a data e hora de produção do evento e quantos milissegundos após a inicialização do ESP32 o evento foi produzido. Também indicam o valor da leitura, o estado atual do dispositivo, a unidade da leitura e a entidade a que ela se refere. O campo de qualidade indica se a leitura é válida ou inválida, e o campo de frescor indica se ela é válida ou expirada. Por fim, o JSON informa quantas tentativas foram realizadas para entregar o payload e qual é o ID do dispositivo.

Amostra:
```json
{"sequence": 209, "eventType": "medicao.vibracao", "eventTimeIso": "2026-09-16T02:09:47Z", "eventTimeMs": 127622, "value": 1.22, "state": "EM_DIA", "ageMs": 57, "quality": "VALIDO", "unit": "xRMS_base", "entityId": "motor-linha3-02", "freshness": "VALIDO", "attempt": 1, "deviceId": "esp32-07"}
```

## 7. Estado, regra e atuação

O funcionamento é baseado em buffer. A leitura é realizada a cada 500 milissegundos e armazenada no buffer. Durante o laço do programa, verifica-se quais leituras ainda estão pendentes de envio no buffer, e elas são enviadas ao MQTT.

A estratégia adotada foi inscrever o dispositivo no tópico MQTT, que é público, para obter a confirmação do recebimento do payload. Assim, o evento é lido, armazenado no buffer e enviado ao MQTT. Ao receber a leitura de retorno, ela é marcada como já enviada, para ser removida do buffer e não ser enviada novamente.

As cores do LED representam o estado do dispositivo naquele momento: se a leitura é válida ou inválida, se existem leituras pendentes de envio ou se a rede caiu, por exemplo.

## 8. Testes

**Estado normal.** O teste mostra o estado em que a leitura é inválida, por exemplo zero. Este é o estado inicial, sem atuação.

**Decisão e atuação.** O teste inclui o estado em que a leitura está sendo feita e o dado está sendo enviado ao MQTT.

**Adversarial.** O teste inclui o estado em que uma queda de rede é simulada por meio do botão. Nesse caso, os eventos são armazenados no buffer, mas têm validade de apenas 20 segundos. Eles são posteriormente enviados ao MQTT quando a rede volta, porém com a marcação de frescor como expirado, como pode ser visto nos prints.

## 9. Limitações da simulação

As limitações são várias, por se tratar de um protótipo, mas incluem: a falha de rede ser simulada pelo botão, e não ser uma falha real; o potenciômetro não ser um sensor real; e, como o hub/gateway não está implementado, o consumidor do tópico MQTT acaba sendo o próprio ESP32.

## 10. Uso de IA generativa

A IA foi utilizada como força executora neste projeto. As decisões arquiteturais e o que seria implementado foram tomados por humanos, mas o código em si foi escrito com auxílio de inteligência artificial. Da mesma maneira, o relatório foi todo produzido, editado e decidido por humano, e apenas transcrito, formatado e padronizado por uma inteligência artificial.
