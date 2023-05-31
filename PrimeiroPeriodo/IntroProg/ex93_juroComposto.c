#include <stdio.h>

int main(){
  double val_ini, taxa, renda, rendimento;
  int meses, i=0;

  scanf("%lf %lf %d", &val_ini, &taxa, &meses);

  for(i=0; i<meses; i++){
    if (i==0){
      rendimento = val_ini * (1+taxa);
    }else{
      rendimento = rendimento * (1+taxa);
    }
    printf("a*(1+r)^%d = %.2lf, renda:  %.2lf\n", i+1, rendimento, rendimento - val_ini);

  }
  return 0;
}
