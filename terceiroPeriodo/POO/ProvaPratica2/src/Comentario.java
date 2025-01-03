import java.util.Date;
import java.util.List;

public class Comentario extends Reacao{
    private String texto;
    private List<Comentario> respostas;

    public Comentario(Usuario usuario, Date data, List<Comentario> respostas, String texto) {
        super(usuario, data);
        this.respostas = respostas;
        this.texto = texto;
    }

    public String getTexto() {
        return texto;
    }

    public void setTexto(String texto) {
        this.texto = texto;
    }

    public List<Comentario> getRespostas() {
        return respostas;
    }

    public void setRespostas(List<Comentario> respostas) {
        this.respostas = respostas;
    }
}
