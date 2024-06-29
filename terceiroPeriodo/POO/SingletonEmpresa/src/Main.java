public class Main {
    public static void main(String[] args) {
        Empresa ebm = Empresa.obtemInstancia("EBM INCORPORACOES S/A", "03.025.881/0002-74", "Rua T 55, 930 SETOR BUENO GOIANIA – GO", "74215-170");

        System.out.println(Empresa.obtemInstancia());

        Projeto projeto = new Projeto(Empresa.obtemInstancia());

        projeto.adicionarColaborador();
        projeto.adicionarConstrucoes();

        System.out.println(Empresa.obtemInstancia());
    }
}