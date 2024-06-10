public class Circulo extends Figura {
    private double raio;

    public Circulo() {
    }

    public Circulo(double raio) {
        this.raio = raio;
    }

    @Override
    public double calcularArea() {
        return Math.PI * Math.pow(raio, 2);
    }

    @Override
    public double calcularPerimetro() {
        return 2 * Math.PI * raio;
    }

    public String desenhar(){
        return "Desenhando a Figura Círculo";
    }

    public double getRaio() {
        return raio;
    }

    public void setRaio(double raio) {
        this.raio = raio;
    }

    @Override
    public String toString() {
        return String.format("Círculo - Raio: %.2f - Área: %.2f - Perímetro: %.2f\n", raio, this.calcularArea(), this.calcularPerimetro());
    }
}
