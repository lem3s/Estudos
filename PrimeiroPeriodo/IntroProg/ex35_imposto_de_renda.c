#include <stdio.h>

int main(){
  int matricula, dependentes;
  double sal_min, sal_fun, taxa, imp_bruto, imp_liq, dif;

  scanf("%d %lf %d %lf %lf", &matricula, &sal_min, &dependentes, &sal_fun, &taxa);

  if (sal_fun > 12*sal_min){
    imp_bruto = sal_fun*0.2;

  }else if (sal_fun > 5*sal_min){
    imp_bruto= sal_fun*0.08;

  }else{
    imp_bruto = 0;
  }
  
  imp_liq = imp_bruto - dependentes * 300;
  dif = imp_liq - (sal_fun * (taxa / 100));

  printf("MATRICULA = %d\n", matricula);
  printf("IMPOSTO BRUTO = %.2lf\n", imp_bruto);
  printf("IMPOSTO LIQUIDO = %.2lf\n", imp_liq);
  printf("RESULTADO = %.2lf\n", dif);

  if (dif < 0){
    printf("IMPOSTO A RECEBER\n");
  } else if (dif == 0){
    printf("IMPOSTO QUITADO\n");
  } else if (dif > 0){
    printf("IMPOSTO A PAGAR\n");
  }
  
  return 0;
}
