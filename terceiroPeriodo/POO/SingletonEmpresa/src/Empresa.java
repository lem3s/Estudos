public final class Empresa {
    private String nome;
    private String cnpj;
    private String endereco;
    private String cep;

    private static Empresa empresa;

    private Empresa(String nome, String cnpj, String endereco, String cep) {
        this.nome = nome;
        this.cnpj = cnpj;
        this.endereco = endereco;
        this.cep = cep;
    }

    private Empresa() {
    }

    public static Empresa obtemInstancia(String nome, String cnpj, String endereco, String cep) {
        if (empresa == null){
            empresa = new Empresa(nome, cnpj, endereco, cep);

            return empresa;
        }

        return empresa;
    }

    public static Empresa obtemInstancia() {
        if (empresa == null){
            empresa = new Empresa();

            return empresa;
        }

        return empresa;
    }

    public String toString() {
        return nome + cnpj + endereco + cep;
    }
}
