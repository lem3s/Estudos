import static org.junit.Assert.*;

import org.junit.After;
import org.junit.AfterClass;
import org.junit.Before;
import org.junit.BeforeClass;
import org.junit.Test;

public class PessoaTest {

    @Test
    public void testFaixa1() {
        Pessoa p = new Pessoa("joão",1500.00,0,20);
        assertEquals(0,p.calculaImposto(),0);

        p = new Pessoa("maria",1500.00,1,50);
        assertEquals(0,p.calculaImposto(),0);

        System.out.println("Passou Teste 1 -  primeira faixa");
    }

    @Test
    public void testFaixa2() {

        Pessoa p = new Pessoa("joão",2000.00,0,60);
        assertEquals(15.91,p.calculaImposto(),0.1);

        p = new Pessoa("joão",2000.00,2,50);
        assertEquals(0,p.calculaImposto(),0);

        System.out.println("Passou Teste 2 - segunda faixa");
    }

    @Test
    public void testFaixa3() {
        Pessoa p = new Pessoa("paulo",3500.00,0,20);
        assertEquals(189.97,p.calculaImposto(),0.1);

        p = new Pessoa("paulo",3500.00,1,20);
        assertEquals(10.26,p.calculaImposto(),0.1);

        p = new Pessoa("paulo",3500.00,2,40);
        assertEquals(0,p.calculaImposto(),0);

        System.out.println("Passou Teste 3 - terceira faixa");
    }

    @Test
    public void testFaixa4() {
        Pessoa p = new Pessoa("paulo",4400.00,0,40);
        assertEquals(387.04,p.calculaImposto(),0.1);

        p = new Pessoa("paulo",4400.00,1,30);
        assertEquals(207.33,p.calculaImposto(),0.1);

        p = new Pessoa("paulo",4400.00,2,40);
        assertEquals(27.62,p.calculaImposto(),0.1);

        p = new Pessoa("paulo",4400.00,3,20);
        assertEquals(0,p.calculaImposto(),0);

        System.out.println("Passou Teste 4 - quarta faixa");
    }

    @Test
    public void testFaixa5() {
        Pessoa p = new Pessoa("jose",7000.00,0,50);
        assertEquals(1098.85,p.calculaImposto(),0.1);

        p = new Pessoa("jose",7000.00,2,30);
        assertEquals(739.43,p.calculaImposto(),0.1);

        p = new Pessoa("paulo",7000.00,6,40);
        assertEquals(20.59,p.calculaImposto(),0.1);

        p = new Pessoa("paulo",7000.00,7,20);
        assertEquals(0,p.calculaImposto(),0);

        System.out.println("Passou Teste 5 - quinta faixa");
    }

    @Test
    public void testFaixa1MaiorDe65Anos() {
        Pessoa p = new Pessoa("José", 1000.00, 2, 70);
        assertEquals(0, p.calculaImposto(), 0);

        p = new Pessoa("Maria", 1500.00, 0, 70);
        assertEquals(0, p.calculaImposto(), 0);

        System.out.println("Passou Teste 6 - primeira faixa com mais de 65 anos");
    }

    @Test
    public void testFaixa2MaiorDe65Anos() {
        Pessoa p = new Pessoa("Antônio", 2100.00, 2, 99);
        assertEquals(0, p.calculaImposto(), 0);

        p = new Pessoa("João", 2000.00, 0, 99);
        assertEquals(0, p.calculaImposto(), 0);

        System.out.println("Passou Teste 7 - segunda faixa com mais de 65 anos");
    }

    @Test
    public void testFaixa3MaiorDe65Anos() {
        Pessoa p = new Pessoa("Ana", 3000.00, 2, 88);
        assertEquals(0, p.calculaImposto(), 0);

        p = new Pessoa("Francisco", 3200.00, 0, 88);
        assertEquals(0, p.calculaImposto(), 0);

        System.out.println("Passou Teste 8 - terceira faixa com mais de 65 anos");
    }

    @Test
    public void testFaixa4MaiorDe65Anos() {
        Pessoa p = new Pessoa("Luiz", 4000.00, 2, 73);
        assertEquals(0, p.calculaImposto(), 0);

        p = new Pessoa("Pedro", 4200.00, 0, 73);
        assertEquals(0, p.calculaImposto(), 0);

        System.out.println("Passou Teste 9 - quarta faixa com mais de 65 anos");
    }

    @Test
    public void testFaixa5MaiorDe65Anos() {
        Pessoa p = new Pessoa("Edison", 8000.00, 2, 100);
        assertEquals(0, p.calculaImposto(), 0);

        p = new Pessoa("Carlos", 9500.00, 0, 100);
        assertEquals(0, p.calculaImposto(), 0);

        System.out.println("Passou Teste 10 - quinta faixa com mais de 65 anos");
    }

    @BeforeClass
    public static void inicializaClass() {
        System.out.println("iniciou série de teste");
    }

    @AfterClass
    public static void finalizaClass() {
        System.out.println("Finalizou série de teste");
    }

}
