#include <stdio.h>

unsigned long int fatorial(int n);

int main(){
  int n; 

  scanf("%d", &n);

  printf("%d! = %ld\n", n, fatorial(n));

  return 0;
}

unsigned long int fatorial(int n){
  unsigned long int produto=1;
  int i=0;

  for(i=1; i<=n; i++){
    produto = produto * i;
  }

  return produto;
}
