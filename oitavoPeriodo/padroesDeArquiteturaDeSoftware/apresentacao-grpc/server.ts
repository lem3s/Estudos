import * as grpc from "@grpc/grpc-js";
import {
  EstoqueService,
  type EstoqueServer,
  type ReservarRequest,
  type ReservarResponse,
  type SkuQuery,
  type EventoEstoque,
} from "./gen/estoque";

// "Banco de dados" em memória.
const saldo = new Map<string, number>([
  ["ABC-1", 5],
  ["XYZ-9", 1],
]);

// --- Unário -----------------------------------------------------------------
function reservar(
  call: grpc.ServerUnaryCall<ReservarRequest, ReservarResponse>,
  callback: grpc.sendUnaryData<ReservarResponse>
) {
  const { sku, qtd, pedidoId } = call.request;
  console.log(`[servidor] Reservar sku=${sku} qtd=${qtd} pedido=${pedidoId}`);

  const disponivel = saldo.get(sku);

  if (disponivel === undefined) {
    // Erro de domínio com código tipado — não um 404 genérico.
    return callback({
      code: grpc.status.NOT_FOUND,
      message: `SKU desconhecido: ${sku}`,
    });
  }

  if (qtd > disponivel) {
    return callback({
      code: grpc.status.FAILED_PRECONDITION,
      message: `Saldo insuficiente: pedido ${qtd}, disponível ${disponivel}`,
    });
  }

  saldo.set(sku, disponivel - qtd);

  callback(null, {
    reservaId: `r-${Date.now()}`,
    restante: disponivel - qtd,
  });
}

// --- Streaming de servidor ---------------------------------------------------
function observar(call: grpc.ServerWritableStream<SkuQuery, EventoEstoque>) {
  const { sku } = call.request;
  console.log(`[servidor] Observar sku=${sku}`);

  let restantes = 5;
  const timer = setInterval(() => {
    if (restantes-- === 0) {
      clearInterval(timer);
      return call.end();
    }
    const atual = saldo.get(sku) ?? 0;
    // Simula movimentação de estoque.
    saldo.set(sku, Math.max(0, atual - 1));
    call.write({
      sku,
      disponivel: saldo.get(sku) ?? 0,
      motivo: "venda",
    });
  }, 700);

  // O cliente pode cancelar: o servidor precisa reagir.
  call.on("cancelled", () => {
    console.log("[servidor] stream cancelado pelo cliente");
    clearInterval(timer);
  });
}

const servidor = new grpc.Server();
servidor.addService(EstoqueService, { reservar, observar } satisfies EstoqueServer);

servidor.bindAsync(
  "0.0.0.0:50051",
  grpc.ServerCredentials.createInsecure(),
  (erro, porta) => {
    if (erro) throw erro;
    console.log(`[servidor] Estoque ouvindo em :${porta}`);
  }
);
