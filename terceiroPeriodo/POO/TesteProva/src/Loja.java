import java.util.ArrayList;

public class Loja {
    private String descricao;
    private ArrayList<Produto> lista = new ArrayList<Produto>();
    Loja(String descricao) {
        this.descricao = descricao;
    }
    public String toString() {
        return "Loja [descricao=" + descricao + ", lista=" + lista + "]";
    }
    public void adicionarProduto(Produto produto) {
        lista.add(produto);
    }
}