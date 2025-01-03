import java.util.Date;

public abstract class Reacao {
    private Date data;
    private Usuario usuario;

    public Reacao(Usuario usuario, Date data) {
        this.usuario = usuario;
        this.data = data;
    }

    public Date getData() {
        return data;
    }

    public void setData(Date data) {
        this.data = data;
    }

    public Usuario getUsuario() {
        return usuario;
    }

    public void setUsuario(Usuario usuario) {
        this.usuario = usuario;
    }
}
