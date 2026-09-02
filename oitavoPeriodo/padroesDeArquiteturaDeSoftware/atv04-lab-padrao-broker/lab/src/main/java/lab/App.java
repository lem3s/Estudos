package lab;

/**
 * Hello world!
 *
 */
public class App 
{
    public static void main( String[] args )
    {
        Broker broker = new Broker();

        broker.registrar("produto", new ProdutoService());

        broker.registrar("consumidor", new ConsumidorService());

        broker.registrar("pedido", new PedidoService());

        String resposta = broker.solicitar("pagamento", "1");

        System.out.println(resposta);

        Cliente cliente = new Cliente(broker);

        cliente.consultarProduto(2);

        cliente.consultarConsumidor(1);

        cliente.consultarPedido(2);
    }
}
