public class Quadrado extends Figura{
    private double lado;

    public Quadrado(){}

    public Quadrado(double lado){
        this.lado = lado;
    }

    @Override
    public double calcularArea() {
        return lado * lado;
    }

    @Override
    public double calcularPerimetro() {
        return lado * 4;
    }

    public String desenhar(){
        return "Desenhando a Figura Quadrado";
    }

    public double getLado() {
        return lado;
    }

    public void setLado(double lado) {
        this.lado = lado;
    }

    @Override
    public String toString() {
        return String.format("Quadrado - Dimensões: %.2f x %.2f - Área: %.2f - Perímetro: %.2f\n", lado, lado, this.calcularArea(), this.calcularPerimetro());
    }
}
