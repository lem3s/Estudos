public class Projeto {
    private Empresa empresa;
    private int numeroDeColaboradores = 0;
    private int numeroDeConstrucoes = 0;

    public Projeto(Empresa empresa) {
        this.empresa = empresa;
    }

    public void adicionarColaborador() {
        numeroDeColaboradores++;
    }

    public void adicionarConstrucoes() {
        numeroDeConstrucoes++;
    }

    public void removerColaborador() {
        numeroDeColaboradores--;
    }

    public void removerConstrucoes() {
        numeroDeConstrucoes--;
    }

    public int getNumeroDeColaboradores() {
        return numeroDeColaboradores;
    }

    public int getNumeroDeConstrucoesSendoFeitas() {
        return numeroDeConstrucoes;
    }
}
