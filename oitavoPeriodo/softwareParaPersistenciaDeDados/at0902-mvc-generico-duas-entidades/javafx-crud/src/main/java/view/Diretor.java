package view;

import javafx.beans.property.SimpleIntegerProperty;
import javafx.beans.property.SimpleStringProperty;

/**
 * ViewModel de Diretor: expõe os dados já formatados para a TableView,
 * desacoplando a tela da entidade de domínio model.Diretor.
 */
public class Diretor {

    private final SimpleIntegerProperty id;
    private final SimpleStringProperty nome;
    private final SimpleStringProperty nacionalidade;
    private final SimpleStringProperty dataNascimento;

    public Diretor(int id, String nome, String nacionalidade, String dataNascimento) {
        this.id = new SimpleIntegerProperty(id);
        this.nome = new SimpleStringProperty(nome);
        this.nacionalidade = new SimpleStringProperty(nacionalidade);
        this.dataNascimento = new SimpleStringProperty(dataNascimento);
    }

    public int getId() {
        return this.id.get();
    }

    public void setId(int id) {
        this.id.set(id);
    }

    public String getNome() {
        return this.nome.get();
    }

    public void setNome(String nome) {
        this.nome.set(nome);
    }

    public String getNacionalidade() {
        return this.nacionalidade.get();
    }

    public void setNacionalidade(String nacionalidade) {
        this.nacionalidade.set(nacionalidade);
    }

    public String getDataNascimento() {
        return this.dataNascimento.get();
    }

    public void setDataNascimento(String dataNascimento) {
        this.dataNascimento.set(dataNascimento);
    }
}
