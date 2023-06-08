#include <stdio.h>

int main(){

  int n, j=2;

  scanf("%d", &n);

  while (j <= n){
    printf("%d^2 = %d\n", j, j*j);
    j = j+2;
  }

  return 0;
}
