#include <stdio.h>

int main(){
  int valor;

  scanf("%d", &valor);

  int notas100 = valor/100;
  int notas50 = (valor%100)/50;
  int notas10 = (valor%50)/10;
  int notas1 = (valor%10);

  printf("NOTAS DE 100 = %d\n", notas100);
  printf("NOTAS DE 50 = %d\n", notas50);
  printf("NOTAS DE 10 = %d\n", notas10);
  printf("MOEDAS DE 1 = %d\n", notas1);
   
  return 0;
}
