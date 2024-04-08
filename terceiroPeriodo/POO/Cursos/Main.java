import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Main {
  public static void main(String[] Args) {
    Scanner sc = new Scanner(System.in);

    System.out.printf("Quantos cursos deseja cadastrar: ");
    int nCursos;
    nCursos = sc.nextInt();

    List<Curso> listaCursos = new ArrayList<>();

    for (int i = 0; i < nCursos; i++) {
      System.out.printf("===== CURSO %d =====\n", i + 1);
      listaCursos.add(new Curso());
    }

    System.out.println();

    for (Curso curso : listaCursos) {
      curso.imprimeInfos();
    }

    sc.close();
  }
}
