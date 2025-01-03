import javax.swing.*;
import java.util.ArrayList;
import java.util.List;

public class Main {
    public static void main(String[] args) {
        var empresa = Empresa.obtemInstancia();
        List<Container> containers = new ArrayList<>();
        List<Material> materiais = new ArrayList<>();

        var contContainer = 1;
        boolean desejaCadastrarOutroContainer;
        do {
            desejaCadastrarOutroContainer = true;
            String textoContainer = String.format("Cadastro do Container %d", contContainer++);
            String tempNomeContainer = JOptionPane.showInputDialog(textoContainer + "\n\nNome: ");

            var tempContainer = new Container(tempNomeContainer, empresa);
            containers.add(tempContainer);

            var contMaterial = 1;
            boolean desejaCadastrarOutroMaterial;
            do {
                String textoMaterial = String.format("Cadastro do Material %d", contMaterial++, contContainer);

                String tempNomeMaterial = JOptionPane.showInputDialog(textoMaterial + "\n\nNome: ");
                int tempCodigoMaterial = Integer.parseInt(JOptionPane.showInputDialog(textoMaterial + "\n\nCodigo: "));

                var tempMaterial = new Material(tempNomeMaterial, tempCodigoMaterial);
                tempMaterial.setContainer(tempContainer);
                materiais.add(tempMaterial);

                Character opcaoMaterial;
                do {
                    opcaoMaterial = JOptionPane.showInputDialog("Deseja criar novo material? [S/N]").charAt(0);
                } while (Character.toUpperCase(opcaoMaterial) != 'N' && Character.toUpperCase(opcaoMaterial) != 'S');

                desejaCadastrarOutroMaterial = !(opcaoMaterial == 'N');

            }while (desejaCadastrarOutroMaterial);

            Character opcaoContainer;
            do {
                opcaoContainer = JOptionPane.showInputDialog("Deseja criar novo Container? [S/N]").charAt(0);
            } while (Character.toUpperCase(opcaoContainer) != 'N' && Character.toUpperCase(opcaoContainer) != 'S');

            desejaCadastrarOutroContainer = !(opcaoContainer == 'N');

        } while (desejaCadastrarOutroContainer);

        JOptionPane.showMessageDialog(null, "Programa finalizado com sucesso!");
    }
}