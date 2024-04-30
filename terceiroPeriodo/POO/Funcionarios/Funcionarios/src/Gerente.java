public class Gerente extends Funcionario {

    public double bonificacao;
    public String tipo;

    public Gerente(String nome, String matricula) {
        super(nome, matricula);
    }

    @Override
    public double salarioAnual() {
        return super.salarioAnual() + bonificacao * 12;
    }
}
