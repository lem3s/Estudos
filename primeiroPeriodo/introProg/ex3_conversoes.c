#include <stdio.h>

int main(){
  float valfah, valpol, valcel, valmil;
  scanf("%f", &valfah);
  scanf("%f", &valpol);
  
  valcel = (5*(valfah-32))/9;
  valmil = valpol * 25.4;

  printf("O VALOR EM CELSIUS = %.2f\n", valcel);
  printf("A QUANTIDADE DE CHUVA E = %.2f\n", valmil);

  return 0;
}
