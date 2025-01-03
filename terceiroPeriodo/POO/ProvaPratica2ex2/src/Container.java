public class Container {
    public static int cont = 0;
    private Empresa empresa;
    private String nome;
    private int codigo;

    Container (String nome, Empresa empresa) {
        this.codigo = ++cont;
        this.nome = nome;
        this.empresa = empresa;
    }

    public String getNome() {
        return nome;
    }
}
