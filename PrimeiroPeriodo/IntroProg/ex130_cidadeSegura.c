#include <stdio.h>

int main(){

  int n,i=0, j=0;

  scanf("%d", &n);

  int matriz[n+1][n+1];

  for(i=0; i<n+1; i++){
    for(j=0; j<n+1; j++){
      scanf("%d", &matriz[i][j]);
    }
  }
  
  for(i=0; i<n; i++){
    for(j=0; j<n; j++){
      if(matriz[i][j] + matriz[i][j+1] + matriz[i+1][j] + matriz[i+1][j+1] >= 2){
        printf("S");
      }
      else{
        printf("U");
      }
    }
    printf("\n");
  }

  return 0;
}
