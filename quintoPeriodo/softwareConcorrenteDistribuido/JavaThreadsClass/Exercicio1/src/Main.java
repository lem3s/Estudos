public class Main {
    public static void main(String[] args) {
        int numeroInicial = 0;
        int numeroFinal = 2000;

        var threadPares = new ImprimeNumeros(numeroInicial, numeroFinal, TipoNumeros.pares);
        var threadImpares = new ImprimeNumeros(numeroInicial, numeroFinal, TipoNumeros.impares);

        threadPares.start();
        threadImpares.start();
    }
}