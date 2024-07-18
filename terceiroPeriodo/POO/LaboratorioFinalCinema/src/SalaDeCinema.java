import java.util.List;

public class SalaDeCinema {
    private int numero;
    private String nome;
    private String localizacao;
    private List<Filme> filmesEmExibicao;

    public SalaDeCinema(int numero, String nome, String localizacao) {
        this.numero = numero;
        this.nome = nome;
        this.localizacao = localizacao;
    }

    public SalaDeCinema(int numero, String nome, String localizacao, List<Filme> filmesEmExibicao) {
        this.numero = numero;
        this.nome = nome;
        this.localizacao = localizacao;
        this.filmesEmExibicao = filmesEmExibicao;
    }

    public void adicionarFilme(Filme filme) {
        filmesEmExibicao.add(filme);
    }

    public int getNumero() {
        return numero;
    }

    public void setNumero(int numero) {
        this.numero = numero;
    }

    public String getNome() {
        return nome;
    }

    public void setNome(String nome) {
        this.nome = nome;
    }

    public String getLocalizacao() {
        return localizacao;
    }

    public void setLocalizacao(String localizacao) {
        this.localizacao = localizacao;
    }

    public List<Filme> getFilmesEmExibicao() {
        return filmesEmExibicao;
    }

    public void setFilmesEmExibicao(List<Filme> filmesEmExibicao) {
        this.filmesEmExibicao = filmesEmExibicao;
    }
}
