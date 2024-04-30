public class Funcionario extends Pessoa {

    public String matricula;
    public double salario;

    public Funcionario(String nome, String matricula) {
        super(nome);
        this.matricula = matricula;
    }

    public double salarioAnual() {
        return salario * 12;
    }

    public String toString() {
        String resultado = String.format("%s - Tel:%s - Matrícula: %s - Salário: R$%.2f", this.nome, this.telefone, this.matricula, this.salario);

        return resultado;
    }
}
