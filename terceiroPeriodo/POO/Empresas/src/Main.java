import javax.swing.*;
import java.util.ArrayList;

public class Main {
    public static void main(String[] args) {
        ArrayList<empresa> listaEmpresas = new ArrayList<empresa>();

        listaEmpresas.add(new empresa("Lenovo", "55.565.527/0001-55", new responsavel("Leticia", "62999229988")));
        listaEmpresas.add(new empresa("Asus", "31.055.499/0001-68", new responsavel("Esdras", "62977883344")));

        String opcaoEmpresa;
        String opcaoProduto;
        opcaoEmpresa = JOptionPane.showInputDialog("Deseja cadastrar uma empresa? (s/N): ");
        while (opcaoEmpresa.equals("s") || opcaoEmpresa.equals("S")) {
            String tempNome;
            String tempCNPJ;
            String tempResponsavel;
            String tempTelefone;

            tempNome = JOptionPane.showInputDialog("Nome da empresa: ");
            tempCNPJ = JOptionPane.showInputDialog("CNPJ: ");
            tempResponsavel = JOptionPane.showInputDialog("Nome do responsavel: ");
            tempTelefone = JOptionPane.showInputDialog("Telefone do responsavel");

            empresa tempEmpresa = new empresa(tempNome, tempCNPJ, new responsavel(tempResponsavel, tempTelefone));

            opcaoProduto = JOptionPane.showInputDialog("Deseja cadastrar um produto? (s/N): ");
            while (opcaoProduto.equals("s") || opcaoProduto.equals("S")) {
                String tempNomeProduto;
                String tempTamanho;
                String tempTipo;
                String tempCor;
                String tempEspecificacao;

                tempNomeProduto = JOptionPane.showInputDialog("Nome do Produto: ");
                tempTamanho = JOptionPane.showInputDialog("Tamanho: ");
                tempTipo = JOptionPane.showInputDialog("Tipo do produto: ");
                tempCor = JOptionPane.showInputDialog("Cor: ");
                tempEspecificacao = JOptionPane.showInputDialog("Especificacao: ");

                tempEmpresa.listaProdutos.add(new produto(tempNomeProduto, tempTamanho, tempTipo, tempCor, tempEspecificacao));

                opcaoProduto = JOptionPane.showInputDialog("Deseja cadastrar outra produto? (s/N): ");
            }

            listaEmpresas.add(tempEmpresa);
            opcaoEmpresa = JOptionPane.showInputDialog("Deseja cadastrar outra empresa? (s/N): ");
        }

        for (empresa empresaX : listaEmpresas) {
            empresaX.paraString();
        }
    }
}