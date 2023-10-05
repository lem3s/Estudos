#include <stdio.h>

void le_numero();

int main(){

  le_numero();

  return 0;
}

void le_numero(){
  int n, i=0;
  double soma=0, aux;

  scanf("%d", &n);

  for(i=0; i<n; i++){
    scanf("%lf", &aux);
    soma += aux;
  }

  printf("%.2lf\n", soma/(double)n);
}
