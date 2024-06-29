import java.util.Scanner;

public class CadastroDocumentos {
    public CadastroDocumentos(){
        int opcao = 0;
        while (opcao < 1 || opcao > 3) {
            Scanner sc = new Scanner(System.in);
            System.out.println("Qual tipo de objeto deseja instanciar?");
            System.out.println("1 - Carta");
            System.out.println("2 - Telegrama");
            System.out.println("3 - Notificacao");

            opcao = sc.nextInt();
        }
        FabricaDocumento fabrica = new FabricaDocumento();
        Documento documento = fabrica.criaDocumento(TipoDocumento.values()[opcao - 1]);

        if (documento instanceof Carta) {
            System.out.println("Carta cadastrada com sucesso!");
        }
        else if (documento instanceof Telegrama) {
            System.out.println("Telegrama cadastrado com sucesso!");
        }
        else if (documento instanceof Notificacao) {
            System.out.println("Telegrama cadastrado com sucesso!");
        }
    }
}
