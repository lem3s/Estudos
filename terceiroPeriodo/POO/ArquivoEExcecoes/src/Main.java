import java.io.*;
import java.util.ArrayList;

public class Main {
    public static void main(String[] args) {
        String arquivoDeEntrada = "/Users/lemes/Estudos/terceiroPeriodo/poo/funcionarios.txt";
        String arquivoDeSaida = "/Users/lemes/Estudos/terceiroPeriodo/poo/funcionarios.dat";
        ArrayList<Funcionario> funcionarios = new ArrayList<>();

        try (BufferedReader br = new BufferedReader(new FileReader(arquivoDeEntrada))) {
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

        try (ObjectOutputStream oos = new ObjectOutputStream(new FileOutputStream(arquivoDeSaida))) {
            oos.writeObject(funcionarios);
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}