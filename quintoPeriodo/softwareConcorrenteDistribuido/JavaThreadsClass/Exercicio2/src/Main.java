import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        int numeroInicial = 0;
        int numeroFinal = 999999;

        Scanner scanner = new Scanner(System.in);
        System.out.println("Quantas threads deseja executar? ");
        int numeroThreads = scanner.nextInt();

        int numerosPorThread = (numeroFinal - numeroInicial) / numeroThreads;
        int restante = (numeroFinal - numeroInicial) % numeroThreads;

        Thread[] threads  = new Thread[numeroThreads];

        long tempoInicial = System.currentTimeMillis();

        for (int i = 0; i < numeroThreads; i++) {
            int numeroInicialThread = numeroInicial + (i * numerosPorThread);
            int numeroFinalThread = numerosPorThread + ((i +1) * numerosPorThread);

            if (i == numeroThreads - 1) {
                numeroFinalThread += restante;
            }

            threads[i] = new Thread(new ThreadEscreveNumeros(numeroInicialThread, numeroFinalThread));

            threads[i].start();
        }

        for (Thread thread : threads) {
            try {
                thread.join();
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }

        long tempoFinal = System.currentTimeMillis();
        System.out.println("Tempo decorrido com " + numeroThreads + " threads: " + (tempoFinal - tempoInicial) + "ms");
    }
}