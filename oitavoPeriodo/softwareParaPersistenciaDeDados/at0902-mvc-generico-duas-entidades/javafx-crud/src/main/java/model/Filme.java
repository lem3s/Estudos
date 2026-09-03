package model;

import java.util.Date;

import com.j256.ormlite.field.DataType;
import com.j256.ormlite.field.DatabaseField;
import com.j256.ormlite.table.DatabaseTable;

@DatabaseTable(tableName = "filme")
public class Filme {

    @DatabaseField(generatedId = true)
    private int id;

    @DatabaseField(dataType = DataType.STRING)
    private String titulo;

    @DatabaseField(dataType = DataType.STRING)
    private String genero;

    @DatabaseField(dataType = DataType.INTEGER)
    private int duracaoMinutos;

    @DatabaseField(dataType = DataType.DATE)
    private Date dataLancamento;

    // foreignAutoRefresh faz o ORMLite carregar o diretor junto com o filme,
    // permitindo filme.getDiretor().getNome() logo após um loadAll()
    @DatabaseField(foreign = true, foreignAutoRefresh = true)
    private Diretor diretor;

    public Filme() {
        super();
    }

    public Filme(String titulo, String genero, int duracaoMinutos, Date dataLancamento, Diretor diretor) {
        this.titulo = titulo;
        this.genero = genero;
        this.duracaoMinutos = duracaoMinutos;
        this.dataLancamento = dataLancamento;
        this.diretor = diretor;
    }

    public int getId() {
        return id;
    }

    public void setId(int id) {
        this.id = id;
    }

    public String getTitulo() {
        return titulo;
    }

    public void setTitulo(String titulo) {
        this.titulo = titulo;
    }

    public String getGenero() {
        return genero;
    }

    public void setGenero(String genero) {
        this.genero = genero;
    }

    public int getDuracaoMinutos() {
        return duracaoMinutos;
    }

    public void setDuracaoMinutos(int duracaoMinutos) {
        this.duracaoMinutos = duracaoMinutos;
    }

    public Date getDataLancamento() {
        return dataLancamento;
    }

    public void setDataLancamento(Date dataLancamento) {
        this.dataLancamento = dataLancamento;
    }

    public Diretor getDiretor() {
        return diretor;
    }

    public void setDiretor(Diretor diretor) {
        this.diretor = diretor;
    }

    @Override
    public String toString() {
        return "Filme [id=" + id + ", titulo=" + titulo + ", genero=" + genero
                + ", duracaoMinutos=" + duracaoMinutos + ", dataLancamento=" + dataLancamento
                + ", diretor=" + diretor + "]";
    }
}
