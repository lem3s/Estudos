public class Material {
    private String nome;
    private int codigo;
    private Container container;

    Material(String nome, int codigo) {
        this.codigo = codigo;
        this.nome = nome;
    }

    public String getNome() {
        return nome;
    }

    public void setContainer( Container container) {
        this. container = container;
    }

    public Container getContainer() {
        return container;
    }
}

