#include <stdio.h>

int main(){

  int temp, maior = -63, i=0, j=0;
  int mat[6][6];

  for(i=0; i<6; i++){
    for(j=0; j<6; j++){
      scanf("%d", &mat[i][j]);
    }
  } 

  for(i=0; i<4; i++){
    for(j=0; j<4; j++){
      temp = mat[i][j] + mat[i][j+1] + mat[i][j+2] + mat[i+1][j+1] + mat[i+2][j] + mat[i+2][j+1] + mat[i+2][j+2];
      if(temp > maior){
        maior = temp;
      }
    }
  }

  printf("%d\n", maior);

  return 0;
}
