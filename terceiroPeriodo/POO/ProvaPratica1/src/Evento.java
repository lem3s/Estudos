import java.util.ArrayList;
import java.util.List;

public class Evento {
    private String descricao;
    private String dataInicio;
    private String dataFim;
    private List<Palestra> palestrasDoEvento = new ArrayList<Palestra>();

    public Evento(String descricao) {
        this.descricao = descricao;
    }

    public String getDescricao() {
        return descricao;
    }

    public void setDescricao(String descricao) {
        this.descricao = descricao;
    }

    public String getDataInicio() {
        return dataInicio;
    }

    public void setDataInicio(String dataInicio) {
        this.dataInicio = dataInicio;
    }

    public String getDataFim() {
        return dataFim;
    }

    public void setDataFim(String dataFim) {
        this.dataFim = dataFim;
    }

    public List<Palestra> getPalestras() {
        return palestrasDoEvento;
    }

    public void setPalestras(List<Palestra> palestrasDoEvento) {
        this.palestrasDoEvento = palestrasDoEvento;
    }

    public void adicionaPalestra(Palestra palestra) {
        this.palestrasDoEvento.add(palestra);
    }

    public String toString() {
        String mensagemDeRetorno;

        mensagemDeRetorno = "Evento: " + descricao + "\n";
        mensagemDeRetorno += "Data de início: " + dataInicio + "\n";
        mensagemDeRetorno += "Data fim: " + dataFim + "\n";

        if (palestrasDoEvento.size() > 0) {
            mensagemDeRetorno += "Palestras do evento: \n";
            for (var palestra : palestrasDoEvento) {
                mensagemDeRetorno += "    ";
                mensagemDeRetorno += palestra.toString() + "\n";
            }
        }

        return mensagemDeRetorno;
    }
}
