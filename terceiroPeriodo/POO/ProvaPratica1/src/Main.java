import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        List<Usuario> usuarios = new ArrayList<>();

        for (int i = 0; i < 2; i++) {
            System.out.printf("### Cadastro do Usuário %d ###\n", i+1);

            System.out.print("Nome: ");
            String tempNome = sc.nextLine();

            System.out.print("Email: ");
            String tempEmail = sc.nextLine();

            System.out.print("Senha: ");
            String tempSenha = sc.nextLine();

            Usuario tempUsuario = new Usuario(tempNome, tempEmail, tempSenha);

            System.out.printf("### Cadastro do Evento do Usuário %d ###\n", i+1);

            System.out.print("Descrição: ");
            String tempDescricao = sc.nextLine();

            System.out.print("Data Inicio: ");
            String tempDataInicio = sc.nextLine();

            System.out.print("Data Fim: ");
            String tempDataFim = sc.nextLine();

            Evento tempEvento1 = new Evento(tempDescricao);
            tempEvento1.setDataInicio(tempDataInicio);
            tempEvento1.setDataFim(tempDataFim);

            for (int j = 0; j < 3; j++) {
                System.out.printf("### Palestra %d do Evento do Usuário %d ###\n", j+1, i+1);

                System.out.print("Nome: ");
                String tempNomePalestra = sc.nextLine();

                System.out.print("Data: ");
                String tempDataPalestra = sc.nextLine();

                System.out.print("Hora Inicial: ");
                String tempHoraInicialPalestra = sc.nextLine();

                System.out.print("Hora Final: ");
                String tempHoraFinalPalestra = sc.nextLine();

                System.out.print("Comentário: ");
                String tempComentarioPalestra = sc.nextLine();

                Palestra tempPalestra = new Palestra(tempNomePalestra, tempDataPalestra);
                tempPalestra.setHoraInicial(tempHoraInicialPalestra);
                tempPalestra.setHoraFinal(tempHoraFinalPalestra);
                tempPalestra.setComentario(tempComentarioPalestra);

                tempEvento1.adicionaPalestra(tempPalestra);
            }

            tempUsuario.adicionaEvento(tempEvento1);

            System.out.printf("### Cadastro do Evento Patrocinado do Usuário %d ###\n", i+1);
            System.out.print("Descrição: ");
            tempDescricao = sc.nextLine();

            System.out.print("Data Inicio: ");
            tempDataInicio = sc.nextLine();

            System.out.print("Data Fim: ");
            tempDataFim = sc.nextLine();

            System.out.print("Patrocinador: ");
            String tempPatrocinador = sc.nextLine();

            System.out.print("Valor do Patrocínio: R$");
            double tempValorDoPatrocinio = sc.nextDouble();

            Evento tempEvento2 = new EventoPatrocinado(tempDescricao, tempPatrocinador, tempValorDoPatrocinio);
            tempEvento2.setDataInicio(tempDataInicio);
            tempEvento2.setDataFim(tempDataFim);

            for (int j = 0; j < 3; j++) {
                System.out.printf("### Palestra %d do Evento Patrocinado do Usuário %d ###\n", j + 1, i + 1);

                System.out.print("Nome: ");
                String tempNomePalestra = sc.nextLine();

                System.out.print("Data: ");
                String tempDataPalestra = sc.nextLine();

                System.out.print("Hora Inicial: ");
                String tempHoraInicialPalestra = sc.nextLine();

                System.out.print("Hora Final: ");
                String tempHoraFinalPalestra = sc.nextLine();

                System.out.print("Comentário: ");
                String tempComentarioPalestra = sc.nextLine();

                Palestra tempPalestra = new Palestra(tempNomePalestra, tempDataPalestra);
                tempPalestra.setHoraInicial(tempHoraInicialPalestra);
                tempPalestra.setHoraFinal(tempHoraFinalPalestra);
                tempPalestra.setComentario(tempComentarioPalestra);

                tempEvento2.adicionaPalestra(tempPalestra);
            }
            tempUsuario.adicionaEvento(tempEvento1);

            usuarios.add(tempUsuario);
        }

        for (var usuario : usuarios) {
            System.out.println(usuario);
        }
    }
}