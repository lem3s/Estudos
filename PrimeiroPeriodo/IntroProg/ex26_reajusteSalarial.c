#include <stdio.h>

int main(){
  float salario_antes, salario_depois;
  
  scanf("%f", &salario_antes);

  if (salario_antes <= 300){
    salario_depois = salario_antes * 1.5;
  }
  if (salario_antes > 300){
    salario_depois = salario_antes * 1.3;
  }
  
  printf("SALARIO COM REAJUSTE = %.2f\n", salario_depois);

  return 0;
}
