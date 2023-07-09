#include <stdio.h>

void inputValor(int *input, int valMin, int valMax);

int main(){

  int linhas, colunas, i=0, j=0;

  inputValor(&linhas, 1, 10);
  inputValor(&colunas, 1, 10);

  int mat[linhas][colunas];

  for(i=0; i<linhas; i++){
    for(j=0; j<colunas; j++){
      scanf("%d", &mat[i][j]);
    }
  }

  for(i=0; i<linhas; i++){
    printf("linha %d: ", i+1);
    for(j=0; j<colunas; j++){
      if(j < colunas-1){
        printf("%d,", mat[i][j]);
      }else{
        printf("%d\n", mat[i][j]);
      }
    }
  }

  return 0;
}

void inputValor(int *input, int valMin, int valMax){
  do{
    scanf("%d", input);
  }while(*input < valMin || *input > valMax);
}
