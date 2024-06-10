public class ContaPoupanca extends Conta{
    public ContaPoupanca(int numero, Cliente dono) {
        super(numero, dono);
    }

    public void atualizaSaldo(double percentual){
        saldo = saldo * percentual;
    }

    public void transferir(double valor, Conta destino){
        this.sacar(valor);
        destino.depositar(valor);
    }
}
