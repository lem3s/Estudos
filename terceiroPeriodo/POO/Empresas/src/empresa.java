import javax.swing.*;
import java.util.ArrayList;

public class empresa {
    private String _nome;
    public String _cnpj;
    public responsavel _responsavel;

    public ArrayList<produto> listaProdutos = new ArrayList<produto>();

    public empresa(String nome, String cnpj, responsavel responsavel) {
        this._nome = nome;
        this._cnpj = cnpj;
        this._responsavel = responsavel;
    }

    public empresa(String nome, String cnpj, responsavel responsavel, ArrayList<produto> listaProdutos) {
        this._nome = nome;
        this._cnpj = cnpj;
        this._responsavel = responsavel;
        this.listaProdutos = listaProdutos;
    }

    public void adicionaLista(produto produto) {
        listaProdutos.add(produto);
    }

    public void paraString() {
        JOptionPane.showMessageDialog(null, String.format("Empresa: %s\nCNPJ: %s\nResponsavel: %s", this._nome, this._cnpj, this._responsavel));
    }
}