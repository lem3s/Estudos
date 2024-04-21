public class Serie extends ProgramaTV {
  int temporadas;
  int episodios;

  public Serie (String nome, String categoria, int temporadas, int episodios) {
    super(nome, categoria);
    this.temporadas = temporadas;
    this.episodios = episodios;
  }

  public String toString () {
    String serie = codigo + "-" + nome + "(" + categoria + ")\n";
    serie = serie + "Diretor : " + diretor + "\n";
    serie = serie + "Artistas : \n";
    for (int i=0;i<artistas.size();i++) {
      serie = serie + artistas.get(i) + "\n";
    }
    serie = serie + "Temporadas : " + temporadas + "\n";
    serie = serie + "Episodios : " + episodios + "\n";

    return serie;
  }
}
