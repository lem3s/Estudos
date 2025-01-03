public final class Empresa {
    public static Empresa instancia;
    String nome;

    private Empresa() {
        nome = "IBM";
    }

    public static Empresa obtemInstancia() {
        if (instancia == null)
            instancia = new Empresa();
        return instancia;
    }

    public String getNome() {
        return nome;
    }
}