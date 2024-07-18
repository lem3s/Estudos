public class Pessoa {
    private String nome;
    private double salario;
    private int dependentes;
    private int idade;

    public Pessoa(String nome, double salario, int dependentes, int idade) {
        this.nome = nome;
        this.salario = salario;
        this.dependentes = dependentes;
        this.idade = idade;
    }

    public double calculaImposto() {

        if (idade >= 65) {
            return 0.0;
        }

        if (salario <= 1787.77){
            return 0.0;
        }
        else if (salario <= 2679.29){
            return (salario * 0.075 - 134.8) - 179.71 * dependentes;
        }
        else if (salario <= 3572.43){
            return (salario * 0.15 - 335.03) - 179.71 * dependentes;
        }
        else if (salario <= 4463.81){
            return (salario * 0.225 - 602.96) - 179.71 * dependentes;
        }
        else {
            return (salario * 0.275 - 826.15) - 179.71 * dependentes;
        }
    }

    public double getSalario() {
        return salario;
    }

    public void setSalario(double salario) {
        this.salario = salario;
    }

    public int getDependentes() {
        return dependentes;
    }

    public void setDependentes(int dependentes) {
        this.dependentes = dependentes;
    }

    public int getIdade() {
        return idade;
    }

    public void setIdade(int idade) {
        this.idade = idade;
    }
}
