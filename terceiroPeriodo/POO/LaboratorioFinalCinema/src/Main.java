import java.io.BufferedWriter;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        List<SalaDeCinema> salasDeCinema = new ArrayList<>();

        var flagSalaDeCinema = true;
        while ( flagSalaDeCinema ) {
           System.out.println("# Cadastro da Sala de Cinema");

            System.out.print("Numero: ");
            int tempNumeroSala = sc.nextInt();

            System.out.print("Nome: ");
            String tempNomeSala = sc.nextLine();

            System.out.print("Localizacao: ");
            String tempLocalizacaoSala = sc.nextLine();

            var tempSalaDeCinema = new SalaDeCinema(tempNumeroSala, tempNomeSala, tempLocalizacaoSala);

            var flagFilme = true;
            while ( flagFilme ) {
                System.out.println("## Cadastro do Filme");

                System.out.print("Nome: ");
                String tempNomeFilme = sc.nextLine();

                System.out.print("Ano de Lancamento: ");
                int tempAnoFilme = sc.nextInt();

                System.out.print("País: ");
                String tempPaisFilme = sc.nextLine();

                System.out.print("Lingua: ");
                String tempLinguaFilme = sc.nextLine();

                System.out.print("Tipo: ");
                String tempTipoFilme = sc.nextLine();

                var tempFilme = new Filme(tempNomeFilme, tempAnoFilme, tempPaisFilme, tempLinguaFilme, tempTipoFilme);

                var flagArtista = true;
                while ( flagArtista ) {
                    System.out.println("## Cadastro de Artista do Filme");

                    System.out.print("Nome: ");
                    String tempNomeArtista = sc.nextLine();

                    System.out.print("Idade (anos): ");
                    int tempIdadeArtista = sc.nextInt();

                    System.out.print("Nacionalidade: ");
                    String tempNacionalidadeArtista = sc.nextLine();

                    tempFilme.adicionarArtista(new Artista(tempNomeArtista, tempIdadeArtista, tempNacionalidadeArtista));

                    Character opcaoArtista;
                    do{
                        System.out.print("Deseja cadastrar outro artista? [S/N]: ");
                        opcaoArtista = sc.next().charAt(0);
                    }
                    while (Character.toUpperCase(opcaoArtista) != 'N' || Character.toUpperCase(opcaoArtista) != 'S');

                    flagArtista = opcaoArtista == 'N';
                }

                tempSalaDeCinema.adicionarFilme(tempFilme);

                Character opcaoFilme;
                do{
                    System.out.print("Deseja cadastrar outro filme? [S/N]: ");
                    opcaoFilme = sc.next().charAt(0);
                }
                while (Character.toUpperCase(opcaoFilme) != 'N' || Character.toUpperCase(opcaoFilme) != 'S');

                flagFilme = opcaoFilme == 'N';
            }

            salasDeCinema.add(tempSalaDeCinema);

            Character opcaoSalaDeCinema;
            do{
                System.out.print("Deseja cadastrar outra sala de cinema? [S/N]: ");
                opcaoSalaDeCinema = sc.next().charAt(0);
            }
            while (Character.toUpperCase(opcaoSalaDeCinema) != 'N' || Character.toUpperCase(opcaoSalaDeCinema) != 'S');

            flagSalaDeCinema = opcaoSalaDeCinema == 'N';
        }

        try (BufferedWriter writer = new BufferedWriter(new FileWriter("salasDeCinema.txt"))) {
            for (var salaDeCinema : salasDeCinema) {
                writer.write(salaDeCinema.toString());
                writer.newLine();
            }
        } catch (IOException e) {
            e.printStackTrace();
        }

        System.out.println("DADOS SALVOS NO ARQUIVO 'salasDeCinema.txt' ");
    }
}