import java.util.List;

public class RedeSocial {
    private String nome;
    private List<Usuario> usuariosInscritos;

    public RedeSocial(String nome, List<Usuario> usuariosInscritos) {
        this.nome = nome;
        this.usuariosInscritos = usuariosInscritos;
    }

    public String getNome() {
        return nome;
    }

    public void setNome(String nome) {
        this.nome = nome;
    }

    public List<Usuario> getUsuariosInscritos() {
        return usuariosInscritos;
    }

    public void setUsuariosInscritos(List<Usuario> usuariosInscritos) {
        this.usuariosInscritos = usuariosInscritos;
    }
}
