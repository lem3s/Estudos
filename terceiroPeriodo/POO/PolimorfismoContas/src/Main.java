import javax.swing.*;
import java.awt.*;
import java.util.ArrayList;
import java.util.List;

public class Main {
    public static void main(String[] args) {
        var teste = new TestaConta();

        List<Conta> contas = new ArrayList<>();

        while (true) {
            int tempNumero = Integer.parseInt(JOptionPane.showInputDialog("Numero: "));

            if(tempNumero == 0){break;}

            String tempNome = JOptionPane.showInputDialog("Nome: ");
            String tempTelefone = JOptionPane.showInputDialog("Telefone: ");

            int tempTipoConta;
            do {
                tempTipoConta = Integer.parseInt(JOptionPane.showInputDialog("Tipo de conta:\n1 - Corrente\n2 - Conta Salário\n3 - Poupança"));
            } while (tempTipoConta < 1 || tempTipoConta > 3);

            Cliente tempCliente = new Cliente(tempNome, tempTelefone);

            switch (tempTipoConta) {
                case (1):
                    ContaCorrente tempContaCorrente = new ContaCorrente(tempNumero, tempCliente);
                    contas.add(tempContaCorrente);
                    break;
                case (2):
                    ContaSalario tempContaSalario = new ContaSalario(tempNumero, tempCliente);
                    contas.add(tempContaSalario);
                    break;
                case (3):
                    ContaPoupanca tempContaPoupanca = new ContaPoupanca(tempNumero, tempCliente);
                    contas.add(tempContaPoupanca);
                    break;
            }
        }

        String mensagemTodasAsContas = "";
        for (Conta conta : contas) {
            mensagemTodasAsContas += conta.toString() + "\n";
        }

        JOptionPane.showMessageDialog(null, mensagemTodasAsContas);
    }
}