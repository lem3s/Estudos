#include <stdio.h>

int main(){
  int conta;
  double consumo, valor;
  char tipo;

  scanf("%d %lf %c", &conta, &consumo, &tipo);

  if (tipo == 'R'){
    valor = 5 + 0.05 * consumo;
  }

  if (tipo == 'C'){
    if (consumo <= 80){
      valor = 500;
    }
    else{
      valor = 500 + (consumo - 80) * 0.25;
    }
  }

  if (tipo == 'I'){
    if (consumo <= 100){
      valor = 800;
    }
    else{
      valor = 800 + (consumo - 100) * 0.04;
    }
  }
  
  printf("CONTA = %d\n", conta);
  printf("VALOR DA CONTA = %.2lf\n", valor);

  return 0;
}
