public class ImprimeNumeros extends Thread {
    private int _numeroInicial;
    private int _numeroFinal;
    private TipoNumeros _tipoDeNumeros;

    public ImprimeNumeros(int numeroInicial, int numeroFinal, TipoNumeros tipoDeNumeros) {
        _numeroInicial = numeroInicial;
        _numeroFinal = numeroFinal;
        _tipoDeNumeros = tipoDeNumeros;
    }

    @Override
    public void run() {
        for (int i = _numeroInicial; i <= _numeroFinal; i++) {
            if (_tipoDeNumeros == TipoNumeros.pares &&
                    i % 2 == 0) {
               System.out.println(i);
            }
            if (_tipoDeNumeros == TipoNumeros.impares &&
                    i % 2 != 0) {
                System.out.println(i);
            }
        }
    }
}
