public class Palestra {
    private String nome;
    private String data;
    private String horaInicial;
    private String horaFinal;
    private String comentario;

    public Palestra(String nome, String data) {
        this.nome = nome;
        this.data = data;
    }

    public String getNome() {
        return nome;
    }

    public void setNome(String nome) {
        this.nome = nome;
    }

    public String getData() {
        return data;
    }

    public void setData(String data) {
        this.data = data;
    }

    public String getHoraInicial() {
        return horaInicial;
    }

    public void setHoraInicial(String horaInicial) {
        this.horaInicial = horaInicial;
    }

    public String getHoraFinal() {
        return horaFinal;
    }

    public void setHoraFinal(String horaFinal) {
        this.horaFinal = horaFinal;
    }

    public String getComentario() {
        return comentario;
    }

    public void setComentario(String comentario) {
        this.comentario = comentario;
    }

    public String toString() {
        return String.format("Palestra: %s - Data: %s - Hora Inicial: %s - Hora Fim: %s - %s", nome, data, horaInicial, horaFinal, comentario);
    }
}
