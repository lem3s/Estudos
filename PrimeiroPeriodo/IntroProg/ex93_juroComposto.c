#include <stdio.h>

int main(){

  double val_ini, taxa, renda;
  int meses;

  scanf("%lf %lf %d", &val_ini, &taxa, &meses);

  int i=1;
  int j=1;
  int n=1;
  int fator;
  fator = 1+taxa;
  for(i=1; i <= meses; i++){

    for(j=0; j < n; j++){
       fator = fator * fator; 
       printf("%d", j);
    }
    printf("a*(1+r)^%d = %.2lf, renda: %.2lf\n", i, val_ini*fator, (val_ini*fator)-val_ini); 
  }
  j=0;
  n++;

  return 0;
}
