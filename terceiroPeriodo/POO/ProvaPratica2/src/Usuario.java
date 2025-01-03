import java.util.List;

public class Usuario {
    private String login;
    private String senha;
    private String nome;
    private String email;

    private List<Usuario> seguidores;
    private List<Usuario> usuariosQueSegue;

    private List<Publicacao> publicacoes;

    public Usuario(String login, String senha, String nome, String email, List<Usuario> usuariosQueSegue, List<Usuario> seguidores, List<Publicacao> publicacoes) {
        this.login = login;
        this.senha = senha;
        this.nome = nome;
        this.email = email;
        this.usuariosQueSegue = usuariosQueSegue;
        this.seguidores = seguidores;
        this.publicacoes = publicacoes;
    }

    public String getLogin() {
        return login;
    }

    public void setLogin(String login) {
        this.login = login;
    }

    public String getSenha() {
        return senha;
    }

    public void setSenha(String senha) {
        this.senha = senha;
    }

    public String getNome() {
        return nome;
    }

    public void setNome(String nome) {
        this.nome = nome;
    }

    public String getEmail() {
        return email;
    }

    public void setEmail(String email) {
        this.email = email;
    }

    public List<Usuario> getUsuariosQueSegue() {
        return usuariosQueSegue;
    }

    public void setUsuariosQueSegue(List<Usuario> usuariosQueSegue) {
        this.usuariosQueSegue = usuariosQueSegue;
    }

    public List<Usuario> getSeguidores() {
        return seguidores;
    }

    public void setSeguidores(List<Usuario> seguidores) {
        this.seguidores = seguidores;
    }

    public List<Publicacao> getPublicacoes() {
        return publicacoes;
    }

    public void setPublicacoes(List<Publicacao> publicacoes) {
        this.publicacoes = publicacoes;
    }
}