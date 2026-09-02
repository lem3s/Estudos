package lab;

public class Cliente {
  private final Broker broker;

  public Cliente(Broker broker) {
    this.broker = broker;
  }

  public void consultarProduto(int id) {
    System.out.println("[Cliente] Consultando produto " + id);

    String resposta = broker.solicitar("produto", String.valueOf(id));

    System.out.println("[Cliente] Resposta: " + resposta);
  }
  
  public void consultarConsumidor(int id) {
    System.out.println("[Cliente] Consultando consumidor " + id);

    String resposta = broker.solicitar("consumidor", String.valueOf(id));

    System.out.println("[Cliente] Resposta: " + resposta);
  }

  public void consultarPedido(int id) {
    System.out.println("[Cliente] Consultando pedido " + id);

    String resposta = broker.solicitar("pedido", String.valueOf(id));

    System.out.println("[Cliente] Resposta: " + resposta);
  }
}
