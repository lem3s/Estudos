#include <stdio.h>

int main(){

  int lin, col, i=0, j=0, flag=0, camisa, gorro, lado1 ,lado2, baixo;

  scanf("%d %d", &lin, &col);

  int mat[lin][col];

  for(i=0; i<lin; i++){
    for(j=0; j<col; j++){
      scanf("%d", &mat[i][j]);
    }
  }

  for(i=0; i<lin; i++){
    for(j=0; j<col; j++){
      camisa = mat[i][j];

      if(i==0){
        gorro = mat[lin-1][j];
      }else{
        gorro = mat[i-1][j];
      }

      if(j==0){
        lado1 = mat[i][col-1]; 
      }else{
        lado1 = mat[i][j-1];
      }

      if(j==col-1){
        lado2 = mat[i][0];
      }else{
        lado2 = mat[i][j+1];
      }

      if(i==lin-1){
        baixo = mat[0][j]; 
      }else{
        baixo = mat[i+1][j];
      }

      if(camisa == 1111 && gorro == 4 && lado1 == 0 && lado2 == 0 && baixo == 8){
        flag = 1;
        printf("%d %d\n", i, j);
        break;
      }
    }
  } 

  if(flag == 0){
    printf("WALLY NAO ESTA NA MATRIZ\n");
  }

  return 0;
}
