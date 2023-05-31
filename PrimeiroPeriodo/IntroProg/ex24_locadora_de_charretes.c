#include <stdio.h>

int main(){
  int horas;
  float valor;

  scanf("%d", &horas);

  valor = (horas / 3)*10 + (horas % 3) *5;

  printf("O VALOR A PAGAR E = %.2f\n", valor);



  return 0;
}
