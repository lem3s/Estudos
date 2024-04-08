public class Produto {
  int cod;
  String nome;
  int quant;
  String tipo;
  double valor;

  public Produto(int cod) {
    this.cod = cod;
  }

  public Produto(int cod, String nome) {
    this.cod = cod;
    this.nome = nome;
  }

  public Produto(int cod, String nome, int quant) {
    this.cod = cod;
    this.nome = nome;
    this.quant = quant;
  }

  public Produto(int cod, String nome, int quant, String tipo, double valor) {
    this.cod = cod;
    this.nome = nome;
    this.quant = quant;
    this.tipo = tipo;
    this.valor = valor;
  }

  public void vender(int quantVenda) {
    if (quantVenda > this.quant) {
      System.out.println("Nao ha estoque suficiente");
      return;
    } else if (this.valor == 0.0) {
      System.out.println("O valor do produto não foi inicializado");
      return;
    }
    this.quant -= quantVenda;
    double valorVenda = (double)quantVenda * this.valor;
    System.out.println("Valor total da venda: " + valorVenda);
  }

  public void comprar(int quantCompra) {
    this.quant += quantCompra;
  }

  public void comprar(double quantCompra, int novoValor) {
    this.quant += quantCompra;
    this.valor = novoValor;
  }

  public void consultar() {
    System.out.println("=== === === === === === === === === === === === === ===");
    System.out.println("Codigo: " + this.cod);
    System.out.println("Nome: " + this.nome);
    System.out.println("Tipo: " + this.tipo);
    System.out.println("Valor: " + this.valor);
    System.out.println("Quantidade em estoque: " + this.quant);
  }

  public void inserir(String novoNome, int novaQuant, String novoTipo, double novoValor) {
    this.nome = novoNome;
    this.quant = novaQuant;
    this.tipo = novoTipo;
    this.valor = novoValor;
  }

  public boolean igual(Produto produtoComparar) {
    return this.nome.equals(produtoComparar.nome) && this.tipo.equals(produtoComparar.tipo);
  }
}
