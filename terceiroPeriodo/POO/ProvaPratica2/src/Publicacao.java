import java.util.Date;
import java.util.List;

public class Publicacao {
    private Date dataPublicacao;
    private String texto;

    private List<Reacao> reacoes;

    public Publicacao(Date dataPublicacao, String texto, List<Reacao> reacoes) {
        this.dataPublicacao = dataPublicacao;
        this.texto = texto;
        this.reacoes = reacoes;
    }

    public Date getDataPublicacao() {
        return dataPublicacao;
    }

    public void setDataPublicacao(Date dataPublicacao) {
        this.dataPublicacao = dataPublicacao;
    }

    public String getTexto() {
        return texto;
    }

    public void setTexto(String texto) {
        this.texto = texto;
    }

    public List<Reacao> getReacoes() {
        return reacoes;
    }

    public void setReacoes(List<Reacao> reacoes) {
        this.reacoes = reacoes;
    }
}
