#include <stdio.h>

int main(){

  int lin, col, i=0, j=0;
  int contadorZero=0, soma=0;

  scanf("%d %d", &lin, &col);

  int mat[lin][col];

  for(i=0; i<lin; i++){
    for(j=0; j<col; j++){
      scanf("%d", &mat[i][j]);
    }
  }

  for(i=0; i<lin; i++){
    for(j=0; j<col; j++){
      if(mat[i][j] == 0){
        contadorZero++;
      }
    }
    if(contadorZero == lin){
      printf("LINHA %d\n", i+1);
    }
    contadorZero = 0;
  }

  for(i=0; i<lin; i++){
    for(j=0; j<col; j++){
      if(mat[j][i] == 0){
        contadorZero++;
      }
    }
    if(contadorZero == col){
      printf("COLUNA %d\n", i+1);
    }
    contadorZero = 0;
  }

  for(i=0; i<lin; i++){
    for(j=0; j<col; j++){
      soma += mat[i][j];
    }
  }

  printf("SOMA: %d\n", soma);

  return 0;
}
