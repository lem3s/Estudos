public class Main {
    public static void main(String[] args) {
        Loja loja = new Loja("Americanas");
        loja.adicionarProduto(new Produto("Livro de Receita"));
        loja.adicionarProduto(new Produto("Caderno"));
        System.out.println(loja);    }
}