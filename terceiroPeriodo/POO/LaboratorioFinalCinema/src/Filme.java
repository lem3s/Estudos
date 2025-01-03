import java.util.List;

public class Filme {
    private String nome;
    private int ano;
    private String paisDeOrigem;
    private String lingua;
    private String tipo;
    private List<Artista> artistas;

    public Filme(String nome, int ano, String paisDeOrigem, String lingua, String tipo) {
        this.nome = nome;
        this.ano = ano;
        this.paisDeOrigem = paisDeOrigem;
        this.lingua = lingua;
        this.tipo = tipo;
    }

    public Filme(List<Artista> artistas, String tipo, String lingua, String paisDeOrigem, int ano, String nome) {
        this.artistas = artistas;
        this.tipo = tipo;
        this.lingua = lingua;
        this.paisDeOrigem = paisDeOrigem;
        this.ano = ano;
        this.nome = nome;
    }

    public void adicionarArtista(Artista artista) {
        artistas.add(artista);
    }

    public String getNome() {
        return nome;
    }

    public void setNome(String nome) {
        this.nome = nome;
    }

    public int getAno() {
        return ano;
    }

    public void setAno(int ano) {
        this.ano = ano;
    }

    public String getPaisDeOrigem() {
        return paisDeOrigem;
    }

    public void setPaisDeOrigem(String paisDeOrigem) {
        this.paisDeOrigem = paisDeOrigem;
    }

    public String getLingua() {
        return lingua;
    }

    public void setLingua(String lingua) {
        this.lingua = lingua;
    }

    public String getTipo() {
        return tipo;
    }

    public void setTipo(String tipo) {
        this.tipo = tipo;
    }

    public List<Artista> getArtistas() {
        return artistas;
    }

    public void setArtistas(List<Artista> artistas) {
        this.artistas = artistas;
    }

    @Override
    public String toString() {
        String stringArtistas = "";
        for (Artista artista : artistas) {
            stringArtistas = stringArtistas + artista.toString() + "\n";
        }

        return "Filme{" +
                "nome='" + nome + '\'' +
                ", ano=" + ano +
                ", paisDeOrigem='" + paisDeOrigem + '\'' +
                ", lingua='" + lingua + '\'' +
                ", tipo='" + tipo + '\'' +
                ", artistas=" + stringArtistas +
                '}';
    }
}
