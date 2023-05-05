#include <stdio.h>

int main(){
  float sal_min, kw, custokw, custoconsumo, custodesconto;
  scanf("%f", &sal_min);
  scanf("%f", &kw);
  
  custokw = (0.7*sal_min)/100.0;
  custoconsumo = custokw*kw;
  custodesconto = custoconsumo*0.9;

  printf("Custo por kW: R$ %.2f\n", custokw);
  printf("Custo do consumo: R$ %.2f\n", custoconsumo);
  printf("Custo com desconto: R$ %.2f\n", custodesconto);

  return 0;
}
