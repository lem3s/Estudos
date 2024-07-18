import java.io.*;
import java.util.ArrayList;

public class Main {
    public static void main(String[] args) {
        String ArquivoDeEntrada = "/Users/lemes/Estudos/terceiroPeriodo/poo/funcionarios.dat";
        ArrayList<Funcionario> funcionarios = new ArrayList<>();

        try {
            FileInputStream arquivoLeitura = new FileInputStream(ArquivoDeEntrada);
            ObjectInputStream objLeitura = new ObjectInputStream(arquivoLeitura);
            funcionarios = (ArrayList<Funcionario>) objLeitura.readObject();
        }
        catch(Exception e) {
            e.printStackTrace();
        }

        Double totalImpostosMasculinos = 0.0;
        Double totalImpostosFemininos = 0.0;
        for (var funcionario : funcionarios) {
            if (funcionario.sexo == 'M') {
                totalImpostosMasculinos += funcionario.impostoRenda();
            }
            else if (funcionario.sexo == 'F') {
                totalImpostosFemininos += funcionario.impostoRenda();
            }
            System.out.println(funcionario.mostraFuncionario());
        }
        System.out.printf("\nImpostos Funcionários Masculinos: %.2f\n", totalImpostosMasculinos);
        System.out.printf("Impostos Funcionários Femininos: %.2f\n", totalImpostosFemininos);
        System.out.printf("Total Impostos: %.2f\n", totalImpostosMasculinos + totalImpostosFemininos);
    }
}