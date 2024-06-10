import java.util.ArrayList;
import java.util.List;

public class Main {
    public static void main(String[] args) {
        System.out.println("Hello world!");
        Retangulo retangulo = new Retangulo(100, 30);

        double area = retangulo.calcularArea();
        double perimetro = retangulo.calcularPerimetro();

        System.out.println("### Retângulo ###");
        System.out.printf("Dimensões: %.2f x %.2f\n", retangulo.getLado(), retangulo.getAltura());
        System.out.printf("Area: %.2f\n", area);
        System.out.printf("Perimetro: %.2f\n\n", perimetro);

        List<Figura> listaFiguras = new ArrayList<>();

        listaFiguras.add(new Quadrado(4));
        listaFiguras.add(new Triangulo(4, 3, 5, 3));
        listaFiguras.add(new Circulo(30));
        listaFiguras.add(new Retangulo(50, 100));

        for (Figura figura : listaFiguras) {
            if (figura instanceof Quadrado) {
                double areaQuadrado = figura.calcularArea();
                double perimetroQuadrado = figura.calcularPerimetro();
            }
            if (figura instanceof Triangulo) {
                double areaTriangulo = figura.calcularArea();
                double perimetroTriangulo = figura.calcularPerimetro();
            }
            if (figura instanceof Circulo) {
                double areaCirculo = figura.calcularArea();
                double perimetroCirculo = figura.calcularPerimetro();
            }
            if (figura instanceof Retangulo) {
                double areaRetangulo = figura.calcularArea();
                double perimetroRetangulo = figura.calcularPerimetro();
            }
            System.out.println(figura.toString());
        }
    }
}