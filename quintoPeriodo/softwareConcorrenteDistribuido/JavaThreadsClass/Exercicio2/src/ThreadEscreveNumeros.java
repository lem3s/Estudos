public class ThreadEscreveNumeros implements Runnable {
    private int _numeroInicial;
    private int _numeroFinal;

    ThreadEscreveNumeros(int numeroInicial, int numeroFinal) {
        _numeroInicial = numeroInicial;
        _numeroFinal = numeroFinal;
    }

    private void ImprimePrimosFaixaDeValores(int valorInicial, int valorFinal) {
        for (int i = valorInicial; i <= valorFinal; i++) {
            for (int j = 2; j <= i; j++) {
                if (i == j) {
                    System.out.println(j);
                }
                if (i % j == 0) {
                   break;
                }
            }
        }
    }

    @Override
    public void run() {
        ImprimePrimosFaixaDeValores(_numeroInicial, _numeroFinal);
    }
}
