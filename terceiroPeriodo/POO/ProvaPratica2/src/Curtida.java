import java.util.Date;

public class Curtida extends Reacao{
    private TiposCurtida tipo;

    public Curtida(Usuario usuario, Date data, TiposCurtida tipo) {
        super(usuario, data);
        this.tipo = tipo;
    }

    public TiposCurtida getTipo() {
        return tipo;
    }

    public void setTipo(TiposCurtida tipo) {
        this.tipo = tipo;
    }
}
