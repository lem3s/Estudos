import * as grpc from "@grpc/grpc-js";
import { EstoqueClient, type EventoEstoque, type ReservarResponse } from "./gen/estoque";

// O stub é a interface: não há URL, nem verbo HTTP, nem DTO escrito à mão.
const estoque = new EstoqueClient(
  "localhost:50051",
  grpc.credentials.createInsecure()
);

function reservar(sku: string, qtd: number, pedidoId: string) {
  return new Promise<ReservarResponse>((resolve, reject) => {
    estoque.reservar(
      { sku, qtd, pedidoId },
      new grpc.Metadata(),
      // Deadline: o contrato inclui quanto tempo o chamador está disposto a esperar.
      { deadline: new Date(Date.now() + 2000) },
      (erro: grpc.ServiceError | null, resposta: ReservarResponse) =>
        erro ? reject(erro) : resolve(resposta)
    );
  });
}

function observar(sku: string) {
  return new Promise<void>((resolve, reject) => {
    const stream = estoque.observar({ sku });
    stream.on("data", (evento: EventoEstoque) =>
      console.log(
        `[cliente] evento: ${evento.sku} -> ${evento.disponivel} (${evento.motivo})`
      )
    );
    stream.on("end", resolve);
    stream.on("error", reject);
  });
}

async function main() {
  const ok = await reservar("ABC-1", 2, "p-77");
  console.log(`[cliente] reserva ${ok.reservaId}, restam ${ok.restante}`);

  try {
    await reservar("XYZ-9", 99, "p-78");
  } catch (erro) {
    const e = erro as grpc.ServiceError;
    console.log(
      `[cliente] recusado: ${grpc.status[e.code]} — ${e.details}`
    );
  }

  console.log("[cliente] observando ABC-1...");
  await observar("ABC-1");
  console.log("[cliente] stream encerrado pelo servidor");
}

main()
  .catch((e) => {
    console.error("[cliente] falhou:", e.message);
    process.exitCode = 1;
  })
  .finally(() => estoque.close());
