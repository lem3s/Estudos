#include <stdio.h>

int main(){
  float preco, dist, imp, cons;

  scanf("%f", &preco);
  scanf("%f", &dist);
  scanf("%f", &imp);

  cons = preco + preco * (dist/100) + preco * (imp/100);

  printf("O VALOR DO CARRO E = %.2f\n", cons);

  return 0;
}
