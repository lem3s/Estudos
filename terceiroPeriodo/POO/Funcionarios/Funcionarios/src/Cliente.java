public class Cliente extends Pessoa {

    public int idade;
    public String cpf;
    private char status;

    public char getStatus() {
        return status;
    }

    public void setStatus(char status) {
        if (status != 'A' && status != 'I') {
            System.out.println("Status inválido");
            return;
        }
        this.status = status;
    }

    public Cliente(String nome, int idade, String cpf) {
        super(nome);
        this.idade = idade;
        this.cpf = cpf;
        this.status = 'A';
    }

    public void desativar() {
        this.status = 'I';
    }

    public String toString() {
        if (status == 'A'){
            String resultado = String.format("%s - Tel: %s - idade: %d anos - cpf: %s - ativo", this.nome, this.telefone, this.idade, this.cpf);

            return resultado;
        }
        String resultado = String.format("%s - Tel: %s - idade: %d anos - cpf: %s - inativo", this.nome, this.telefone, this.idade, this.cpf);

        return resultado;
    }
}
