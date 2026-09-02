package lab;

public class PedidoService implements Servico{
  @Override
  public String executar(String parametro) {
    int id = Integer.parseInt(parametro);

    switch (id) {
      case 1:
        return "1x Notebook, 1x Mouse";
      case 2:
        return "1x Teclado, 1x Mouse";
      case 3:
        return "5x Teclado";
      default:
        return "Pedido não encontrado";
    }
  }
}
