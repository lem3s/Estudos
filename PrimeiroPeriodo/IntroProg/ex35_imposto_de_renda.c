#include <stdio.h>

int main(){
  int matricula, dependentes;
  double sal_min, sal_fun, taxa, imposto;

  scanf("%d %lf %d %lf %lf", &matricula, &sal_min, &dependentes, &sal_fun, &taxa);

  if (sal_fun > sal_min*12){
    imposto = sal_fun*0.2;
  }else if (sal_fun > sal_min*5){
    imposto= sal_fun*0.08;
  }else{
    imposto = 0;
  }


  
  return 0;
}
