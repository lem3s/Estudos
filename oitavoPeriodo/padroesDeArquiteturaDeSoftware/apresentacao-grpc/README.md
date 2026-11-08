# Demo gRPC — Pedidos → Estoque

Dois processos Node/TypeScript trocando chamadas gRPC, para a apresentação de
Padrões de Arquitetura de Software.

## Rodar

```bash
npm install

# gera gen/estoque.ts a partir do .proto (protoc + ts-proto)
npm run proto:gen

# terminal 1
npm run server

# terminal 2
npm run client
```

## Saída esperada

```
[cliente] reserva r-1758..., restam 3
[cliente] recusado: FAILED_PRECONDITION — Saldo insuficiente: pedido 99, disponível 1
[cliente] observando ABC-1...
[cliente] evento: ABC-1 -> 2 (venda)
[cliente] evento: ABC-1 -> 1 (venda)
...
[cliente] stream encerrado pelo servidor
```

## Roteiro de apresentação

**Antes de começar:** rode `npm run proto:gen` uma vez só pra confirmar que o
`protoc` funciona na máquina que vai projetar (ele já vem do Homebrew nesta
máquina). Pode deixar `gen/` gerado como plano B, mas regenere ao vivo no
passo 2 — é o momento que prova que os tipos não são escritos à mão.

1. **O `.proto` é a fonte da verdade.** Abra `estoque.proto`. Fale: "isso é a
   única coisa que cliente e servidor compartilham — não tem SDK, não tem
   código copiado entre os dois lados."

2. **Gera os tipos ao vivo.**
   ```bash
   npm run proto:gen
   ```
   Abra o `gen/estoque.ts` gerado e mostre rapidamente `EstoqueClient`,
   `EstoqueService`, os campos `pedidoId`/`reservaId` em camelCase. Fale:
   "isso não fui eu que escrevi — saiu do `.proto` agora mesmo."

3. **Sobe o servidor** (terminal 1): `npm run server`.

4. **Roda o cliente** (terminal 2): `npm run client`, e narre a saída ponto a
   ponto:
   - **A chamada parece local.** `estoque.reservar(...)` em `client.ts` não
     tem URL nem `fetch`. É esse o ponto do modelo RPC — e a crítica de Waldo.
   - **O erro chega tipado.** A segunda chamada pede 99 unidades de um SKU
     com 1. O servidor devolve `FAILED_PRECONDITION`, não um 409 que o
     cliente precisa interpretar.
   - **O deadline faz parte da chamada.** `{ deadline: ... }` em `client.ts`.
     Num sistema real ele se propaga para os próximos saltos.
   - **Streaming na mesma conexão.** `Observar` devolve N eventos sem polling
     e sem WebSocket separado.

### Bônus: prova que não é mock

Renomeie um campo no `.proto` ao vivo (ex.: `pedido_id` → `pedido_ref`), rode
`npm run proto:gen` de novo e tente compilar:
```bash
npx tsc --noEmit
```
O `tsc` acusa erro em `client.ts`/`server.ts` porque `pedidoId` não existe
mais — dessincronia entre cliente e servidor vira erro de compilação, não bug
em produção. Reverta o `.proto` e rode `proto:gen` de novo antes de seguir.

### Plano B

Se `protoc` falhar na hora (rede, ambiente da sala), tenha `gen/` já gerado
localmente e pule direto pro passo 3 — a saída esperada está documentada
acima ("Saída esperada") caso precise só narrar sem rodar.

## Honestidade sobre a demo

- Os tipos em `gen/estoque.ts` **não são escritos à mão** — são gerados pelo
  `protoc` com o plugin `ts-proto` (`npm run proto:gen`), a partir de
  `estoque.proto`. É o mesmo fluxo de um projeto real: o `.proto` é o artefato
  de build, o código TypeScript é derivado dele. Por isso `gen/` não é
  versionado (`.gitignore`) — se apagar a pasta, `npm run proto:gen` recria
  tudo.
- `client.ts`/`server.ts` importam o client (`EstoqueClient`) e a definição de
  serviço (`EstoqueService`) diretamente do código gerado — sem
  `@grpc/proto-loader`, sem `as any`. Se alguém renomear um campo no `.proto`
  e esquecer de atualizar um dos dois lados, o `tsc` acusa erro de compilação,
  não uma falha em produção.
- A conexão é insegura (`createInsecure`). Em produção, TLS.
