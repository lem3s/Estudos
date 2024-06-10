public class Retangulo extends Quadrado {
    private double altura;

    public Retangulo() {
    }

    public Retangulo(double lado, double altura) {
        super(lado);
        this.altura = altura;
    }

    @Override
    public double calcularArea() {
        return getLado() * this.altura;
    }

    @Override
    public double calcularPerimetro() {
        return getLado() * 2 + this.altura * 2;
    }

    public String desenhar(){
        return "Desenhando a Figura Retângulo";
    }

    public double getAltura() {
        return altura;
    }

    public void setAltura(double altura) {
        this.altura = altura;
    }

    @Override
    public String toString() {
        return String.format("Retângulo - Dimensões: %.2f x %.2f - Área: %.2f - Perímetro: %.2f\n", getLado(), altura, this.calcularArea(), this.calcularPerimetro());
    }
}
