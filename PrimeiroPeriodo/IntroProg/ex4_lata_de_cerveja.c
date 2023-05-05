#include <stdio.h>
#define pi 3.14159

int main(){
  float raio, altura, custo;
  scanf("%f", &raio);
  scanf("%f", &altura);

  custo = ((2*(pi * (raio*raio))) + (2*pi*raio*altura)) * 100;

  printf("O VALOR DO CUSTO E = %.2f\n", custo);

  return 0;
}
