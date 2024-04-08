import javax.swing.JOptionPane; 

public class Main {
  public static void main(String[] args) {
    JOptionPane.showMessageDialog(null, "Crie um objeto do tipo 'public Produto (int codigoDoProduto)'");
    int tempCod = Integer.parseInt(JOptionPane.showInputDialog("Codigo:"));
    Produto produto1 = new Produto(tempCod);

    JOptionPane.showMessageDialog(null, "Crie um objeto do tipo 'public Produto (int codigoDoProduto, String nomeDoProduto)'");
    tempCod = Integer.parseInt(JOptionPane.showInputDialog("Codigo:"));
    String tempNome = JOptionPane.showInputDialog("Nome:");
    Produto produto2 = new Produto(tempCod, tempNome);

    JOptionPane.showMessageDialog(null, "Crie um objeto do tipo 'public Produto (int codigoDoProduto, String nomeDoProduto, int quantidadeDoProduto)'");
    tempCod = Integer.parseInt(JOptionPane.showInputDialog("Codigo:"));
    tempNome = JOptionPane.showInputDialog("Nome:");
    int tempQuant = Integer.parseInt(JOptionPane.showInputDialog("Quantidade em estoque:"));
    Produto produto3 = new Produto(tempCod, tempNome, tempQuant);

    JOptionPane.showMessageDialog(null, "Crie um objeto do tipo 'public Produto (int codigoDoProduto, String nomeDoProduto, int quantidadeDoProduto, String tipoDoProduto, double valorDoProduto)'");
    tempCod = Integer.parseInt(JOptionPane.showInputDialog("Codigo:"));
    tempNome = JOptionPane.showInputDialog("Nome:");
    tempQuant = Integer.parseInt(JOptionPane.showInputDialog("Quantidade em estoque:"));
    String tempTipo = JOptionPane.showInputDialog("Tipo:");
    double tempValor = Double.parseDouble(JOptionPane.showInputDialog("Valor:"));
    Produto produto4 = new Produto(tempCod, tempNome, tempQuant, tempTipo, tempValor);

    produto1.consultar();
    produto2.consultar();
    produto3.consultar();
    produto4.consultar();

    JOptionPane.showMessageDialog(null, "Altere os dados do objeto criado com o primeiro construtor");
    tempNome = JOptionPane.showInputDialog("Nome:");
    tempQuant = Integer.parseInt(JOptionPane.showInputDialog("Quantidade em estoque:"));
    tempTipo = JOptionPane.showInputDialog("Tipo:");
    tempValor = Double.parseDouble(JOptionPane.showInputDialog("Valor:"));
    produto1.inserir(tempNome, tempQuant, tempTipo, tempValor);

    System.out.println();
    produto1.consultar();
    produto2.consultar();
    produto3.consultar();
    produto4.consultar();

    System.out.println();
    System.out.println("Operações produto 1");
    produto1.vender(10);
    produto1.comprar(25);
    produto1.comprar(25, 10);
    produto1.igual(produto4);   

    System.out.println("Operações produto 2");
    produto2.vender(10);
    produto2.comprar(25);
    produto2.comprar(25, 10);
    produto2.igual(produto4);   

    System.out.println("Operações produto 3");
    produto3.vender(10);
    produto3.comprar(25);
    produto3.comprar(25, 10);
    produto3.igual(produto4);   

    System.out.println("Operações produto 4");
    produto4.vender(10);
    produto4.comprar(25);
    produto4.comprar(25, 10);
    produto4.igual(produto4);   

    System.out.println();
    produto1.consultar();
    produto2.consultar();
    produto3.consultar();
    produto4.consultar();
  }
}
