import java.util.Scanner;

public class Curso {
  String nome;
  String docente;
  int horas;
  String sala; 

  public Curso() {
    Scanner sc = new Scanner(System.in);
    System.out.print("Nome da Matéria: ");
    this.nome = sc.nextLine();
    System.out.print("Docente: ");
    this.docente = sc.nextLine();
    System.out.print("Sala: ");
    this.sala = sc.nextLine();
    System.out.print("Carga Horária: ");
    this.horas = sc.nextInt();

    sc.close();
  }

  public void imprimeInfos() {
    System.out.println("=====" + this.nome + "=====");
    System.out.println("Docente: " + this.docente);
    System.out.println("Sala: " + this.sala);
    System.out.println("Carga Horária: " + this.horas);
  }
}
