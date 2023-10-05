#include <stdio.h>

int main(){

  int linhas, colunas, n=1, i=0, j=0;

  scanf("%d %d", &linhas, &colunas);

  for(i=1; i<=linhas; i++){
    if(i%2 != 0){
      for(j=1; j<=colunas; j++){
        if(j%2 != 0){
          printf("0 ");
        }
        if(j%2 == 0){
          printf("%d ", n);
          n++;
        }
      }
      printf("\n");
    }
    if(i%2 == 0){
      for(j=1; j<=colunas; j++){
        if(j%2 != 0){
          printf("%d ", n);
          n++;
        }
        if(j%2 == 0){
          printf("0 ");
        }
      }
      printf("\n");
    }
  } 



  return 0;
}
