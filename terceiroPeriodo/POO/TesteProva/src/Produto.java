public class Produto {
    private int codigo;
    private String descricao;
    public Produto(String descricao) {
        this.descricao = descricao;
    }
    public Produto(int codigo, String descricao) {
        this.codigo = codigo;
        this.descricao = descricao;
    }
}