public class Triangulo extends Figura {
    private double base;
    private double lado1;
    private double lado2;
    private double altura;

    public Triangulo(){}

    public Triangulo(double base, double lado1, double lado2, double altura) {
        this.base = base;
        this.lado1 = lado1;
        this.lado2 = lado2;
        this.altura = altura;
    }

    @Override
    public double calcularArea() {
        return (base * altura) / 2;
    }

    @Override
    public double calcularPerimetro() {
        return base+lado1+lado2;
    }

    public String desenhar(){
        return "Desenhando a Figura Triângulo";
    }

    public double getBase() {
        return base;
    }

    public void setBase(double base) {
        this.base = base;
    }

    public double getLado1() {
        return lado1;
    }

    public void setLado1(double lado1) {
        this.lado1 = lado1;
    }

    public double getLado2() {
        return lado2;
    }

    public void setLado2(double lado2) {
        this.lado2 = lado2;
    }

    public double getAltura() {
        return altura;
    }

    public void setAltura(double altura) {
        this.altura = altura;
    }

    @Override
    public String toString() {
        return String.format("Triângulo - Dimensões: %.2f x %.2f x %.2f - Área: %.2f - Perímetro: %.2f\n", base, lado1, lado2, this.calcularArea(), this.calcularPerimetro());
    }
}
