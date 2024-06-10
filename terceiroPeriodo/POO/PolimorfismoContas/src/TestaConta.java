public class TestaConta {

    public TestaConta() {
        ContaCorrente contaCorrente1 = new ContaCorrente(1, new Cliente("Jose Bezerra", "66999599493"));
        ContaPoupanca contaPoupanca1 = new ContaPoupanca(2, new Cliente("Britany Alanny", "76959899093"));

        contaCorrente1.depositar(100.0);
        contaPoupanca1.depositar(100.0);

        System.out.println("Deposito de R$100,00");
        System.out.println(contaCorrente1);
        System.out.println(contaPoupanca1);

        contaCorrente1.sacar(50.0);
        contaPoupanca1.sacar(50.0);

        System.out.println("Saque de R$50,00");
        System.out.println(contaCorrente1);
        System.out.println(contaPoupanca1);

        ((ContaPoupanca) contaPoupanca1).atualizaSaldo(0.5);
        System.out.println("Saldo atualizado em 50%");
        System.out.println(contaPoupanca1);

        ContaCorrente contaCorrente2 = new ContaCorrente(3, new Cliente("Lorrainy Vecanandre", "66999599493"));
        ContaPoupanca contaPoupanca2 = new ContaPoupanca(4, new Cliente("Wellerson de Morais", "76959899093"));

        contaCorrente1.transferir(10, contaCorrente2);
        System.out.println("Conta corrente 1 apos duas transferencias");
        System.out.println(contaCorrente1);

        contaCorrente1.transferir(10, contaPoupanca2);
        System.out.println("Transferência entre contas diferentes");
        System.out.println(contaPoupanca2);
    }

}
