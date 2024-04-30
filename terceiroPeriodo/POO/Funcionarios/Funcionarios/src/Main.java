public class Main {
    public static void main(String[] args)
    {
        Caixa caixa1 = new Caixa("Jeferson", "0001");

        caixa1.horario = 8;
        caixa1.telefone = "62 91234-5678";
        caixa1.salario = 1410.22;

        caixa1.salario = caixa1.salario * 1.1;

        System.out.println(caixa1);
        System.out.println(String.format("Recebimento anual: %.2f", caixa1.salarioAnual()));

        Gerente gerente1 = new Gerente("Emilio", "0002");
        gerente1.telefone = "62 98989-3434";
        gerente1.salario = 5496.55;
        gerente1.bonificacao = 500;
        gerente1.tipo = "PF";

        gerente1.salario = gerente1.salario * 1.2;

        System.out.println(gerente1);

        Cliente cliente1 = new Cliente("Alessandra", 46, "748348588-88");
        cliente1.telefone = "62 97777-6666";
        Cliente cliente2 = new Cliente("Medeiros", 20, "040348588-77");
        cliente2.telefone = "62 8888-9999";
        Cliente cliente3 = new Cliente("Erick", 28, "640948688-66");
        cliente3.telefone = "62 91111-2222";

        cliente2.desativar();

        System.out.println(cliente1.toString());
        System.out.println(cliente2.toString());
        System.out.println(cliente3.toString());
    }
}