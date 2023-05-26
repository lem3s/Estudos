#include <stdio.h>

int main(){

  int x, y, i;

  scanf("%d %d",  &x, &y);

  if (x%2 == 0){
    i=0;
    for(i=0; i<y; i++){
      printf("%d ", x + 2*i);
    } 
    printf("\n");
  }
  else{
    printf("O PRIMEIRO NUMERO NAO E PAR\n");
  }

  return 0;
}
