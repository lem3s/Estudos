import java.util.ArrayList;
import java.util.List;

public class Usuario {
    private String nome;
    private String email;
    private String senha;
    private List<Evento> eventosQueParticipa = new ArrayList<Evento>();

    public Usuario(String nome, String email, String senha) {
        this.nome = nome;
        this.email = email;
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

    public String getSenha() {
        return senha;
    }

    public void setSenha(String senha) {
        this.senha = senha;
    }

    public List<Evento> getEventos() {
        return eventosQueParticipa;
    }

    public void setEventos(List<Evento> eventosQueParticipa) {
        this.eventosQueParticipa = eventosQueParticipa;
    }

    public void adicionaEvento(Evento evento) {
        this.eventosQueParticipa.add(evento);
    }

    public String toString() {
        String mensagemDeRetorno;

        mensagemDeRetorno = "Usuário: " + this.nome + "\n";
        mensagemDeRetorno += "Email: " + this.email + "\n";

        if (eventosQueParticipa.size() > 0) {
            mensagemDeRetorno += "Eventos participante:\n";

            for (Evento evento : eventosQueParticipa) {
                mensagemDeRetorno += "    ";
                mensagemDeRetorno += evento.toString();
            }
        }

        return mensagemDeRetorno;
    }
}
