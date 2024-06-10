public class ContaSalario extends ContaCorrente{
    public ContaSalario(int numero, Cliente dono) {
        super(numero, dono);
    }

    @Override
    public void depositar(double valor) {
        this.saldo += valor - 0.1;
    }

    @Override
    public void sacar(double valor) {
        this.saldo -= valor - 0.1;
    }
}
