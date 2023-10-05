#include <stdio.h>

int main(){

  float n, i, k, s;

  scanf("%f", &n); //Número
  scanf("%f", &i); //Inicio do segundo operador
  scanf("%f", &k); //N de valores p incremento
  scanf("%f", &s); //Incremento

  printf("Tabuada de soma:\n");
  int j=0;
  for(j=0; j < k; j++){
    printf("%.2f + %.2f = %.2f\n", n, i+(s*j), n + (i + (s*j)));
  }

  printf("Tabuada de subtracao:\n");
  j=0;
  for(j=0; j < k; j++){
    printf("%.2f - %.2f = %.2f\n", n, i+(s*j), n - (i + (s*j)));
  }

  printf("Tabuada de multiplicacao:\n");
  j=0;
  for(j=0; j < k; j++){
    printf("%.2f * %.2f = %.2f\n", n, i+(s*j), n * (i + (s*j)));
  }

  printf("Tabuada de divisao:\n");
  j=0;
  for(j=0; j < k; j++){
    printf("%.2f / %.2f = %.2f\n", n, i+(s*j), n / (i + (s*j)));
  }
  return 0;
}
