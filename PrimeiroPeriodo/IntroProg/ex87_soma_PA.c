#include <stdio.h>

int main(){

  int ini, raz, n, soma;

  scanf("%d %d %d", &ini, &raz, &n);

  int i=0;
  for (i=0; i < n; i++){
    soma += ini + i * raz;
  }

  printf("%d\n", soma);

  return 0;
}
