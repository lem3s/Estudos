#include <stdio.h>

struct Cursos {
  int cod;
  float val;
  char nome[100];
};

struct Aluno {
  char nome[500];
  int cod;
  int cred;
};

int main(){
  int nCursos, nAlunos, i=0, j=0;
  int codAluno, indexCurso;

  scanf("%d", &nCursos);

  struct Cursos cursos[nCursos];

  for(i=0; i<nCursos; i++){
    scanf("%d", &cursos[i].cod);
    scanf("%f", &cursos[i].val);
    getchar();
    fgets(cursos[i].nome, sizeof(cursos[i].nome), stdin);
  }

  /*
  scanf("%d", &nAlunos);
  struct Aluno alunos[nAlunos];

  for(i=0; i<nAlunos; i++){
    fgets(alunos[i].nome, sizeof(alunos[i].nome), stdin);
    scanf("%d", &alunos[i].cod);
    scanf("%d", &alunos[i].cred);
    getchar();
  }

  for(i=0; i<nAlunos; i++){
    codAluno = alunos[i].cod;

    for(j=0; j<nCursos; j++){
      if(cursos[j].cod == codAluno){
        indexCurso = j;
        break;
      }
    }

    printf("Aluno(a): %s Curso: %s Num. Creditos: %d Valor Credito: %f Mensalidade: %lf", alunos[i].nome, cursos[indexCurso].nome, alunos[i].cred, cursos[indexCurso].val, alunos[i].cred*cursos[indexCurso].val);
  }
  */

  return 0;
}
