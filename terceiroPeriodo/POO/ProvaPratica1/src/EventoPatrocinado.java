public class EventoPatrocinado extends Evento {
    private String nomeDoPatrocinador;
    private double valor;

    public EventoPatrocinado(String descricao, String nomeDoPatrocinador, double valor) {
        super(descricao);
        this.nomeDoPatrocinador = nomeDoPatrocinador;
        this.valor = valor;
    }

    public String getNomeDoPatrocinador() {
        return nomeDoPatrocinador;
    }

    public void setNomeDoPatrocinador(String nomeDoPatrocinador) {
        this.nomeDoPatrocinador = nomeDoPatrocinador;
    }

    public double getValor() {
        return valor;
    }

    public void setValor(double valor) {
        this.valor = valor;
    }

    public String toString() {
        String mensagemDeRetorno;

        mensagemDeRetorno = "Evento: " + getDescricao() + "\n";
        mensagemDeRetorno += "Patrocinador: " + nomeDoPatrocinador + "\n";
        mensagemDeRetorno += "Data de início: " + getDataInicio() + "\n";
        mensagemDeRetorno += "Data fim: " + getDataFim() + "\n";

        if (getPalestras().size() > 0) {
            mensagemDeRetorno += "Palestras do evento: \n";
            for (var palestra : getPalestras()) {
                mensagemDeRetorno += "    ";
                mensagemDeRetorno += palestra.toString();
            }
        }

        return mensagemDeRetorno;
    }
}
