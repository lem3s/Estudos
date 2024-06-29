import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.IOException;
import java.util.ArrayList;

public class Main {
    public static void main(String[] args) {
        String ArquivoDeEntrada = "/Users/lemes/Estudos/terceiroPeriodo/poo/funcionarios.txt";
        ArrayList<Funcionario> funcionarios = new ArrayList<>();

        try (BufferedReader br = new BufferedReader(new FileReader(ArquivoDeEntrada))) {
            String line;
            while ((line = br.readLine()) != null) {
                String[] parts = line.split("#");
                String tempNome = parts[0];
                char tempSexo = parts[1].charAt(0);
                Double tempSalario = Double.parseDouble(parts[2]);
                int tempDependentes = Integer.parseInt(parts[3]);

                funcionarios.add(new Funcionario(tempNome, tempSexo, tempSalario, tempDependentes));
            }
        } catch (IOException e) {
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