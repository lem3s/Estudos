public class Artista {
    private String nome;
    private int idade;
    private String nacionalidade;

    public Artista(String nome, int idade, String nacionalidade) {
        this.nome = nome;
        this.idade = idade;
        this.nacionalidade = nacionalidade;
    }

    @Override
    public String toString() {
        return "Artista{" +
                "nome='" + nome + '\'' +
                ", idade=" + idade +
                ", nacionalidade='" + nacionalidade + '\'' +
                '}';
    }
}
