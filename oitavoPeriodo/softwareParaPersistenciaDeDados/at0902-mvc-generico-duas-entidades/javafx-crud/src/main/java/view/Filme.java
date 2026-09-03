package view;

import javafx.beans.property.SimpleIntegerProperty;
import javafx.beans.property.SimpleStringProperty;

/**
 * ViewModel de Filme. A chave estrangeira é achatada em dois campos:
 * diretorId (usado para reselecionar o ComboBox) e diretorNome (exibido
 * na coluna da tabela).
 */
public class Filme {

    private final SimpleIntegerProperty id;
    private final SimpleStringProperty titulo;
    private final SimpleStringProperty genero;
    private final SimpleIntegerProperty duracaoMinutos;
    private final SimpleStringProperty dataLancamento;
    private final SimpleIntegerProperty diretorId;
    private final SimpleStringProperty diretorNome;

    public Filme(int id, String titulo, String genero, int duracaoMinutos,
                 String dataLancamento, int diretorId, String diretorNome) {
        this.id = new SimpleIntegerProperty(id);
        this.titulo = new SimpleStringProperty(titulo);
        this.genero = new SimpleStringProperty(genero);
        this.duracaoMinutos = new SimpleIntegerProperty(duracaoMinutos);
        this.dataLancamento = new SimpleStringProperty(dataLancamento);
        this.diretorId = new SimpleIntegerProperty(diretorId);
        this.diretorNome = new SimpleStringProperty(diretorNome);
    }

    public int getId() {
        return this.id.get();
    }

    public void setId(int id) {
        this.id.set(id);
    }

    public String getTitulo() {
        return this.titulo.get();
    }

    public void setTitulo(String titulo) {
        this.titulo.set(titulo);
    }

    public String getGenero() {
        return this.genero.get();
    }

    public void setGenero(String genero) {
        this.genero.set(genero);
    }

    public int getDuracaoMinutos() {
        return this.duracaoMinutos.get();
    }

    public void setDuracaoMinutos(int duracaoMinutos) {
        this.duracaoMinutos.set(duracaoMinutos);
    }

    public String getDataLancamento() {
        return this.dataLancamento.get();
    }

    public void setDataLancamento(String dataLancamento) {
        this.dataLancamento.set(dataLancamento);
    }

    public int getDiretorId() {
        return this.diretorId.get();
    }

    public void setDiretorId(int diretorId) {
        this.diretorId.set(diretorId);
    }

    public String getDiretorNome() {
        return this.diretorNome.get();
    }

    public void setDiretorNome(String diretorNome) {
        this.diretorNome.set(diretorNome);
    }
}
