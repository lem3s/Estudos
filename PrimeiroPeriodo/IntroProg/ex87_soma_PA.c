#include <stdio.h>

int main(){

  int ini, raz, n, soma, i=0;

  scanf("%d %d %d", &ini, &raz, &n);

  for (i=0; i < n; i++){
    soma += ini + i * raz;
  }

  printf("%d\n", soma);

  return 0;
}
