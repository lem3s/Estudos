#include <stdio.h>

int main(){

  int n, i = 0;
  double soma = 0.0, j = 0.0;

  scanf("%d", &n);

  if (n > 1){
    for(i=0; i < n; i++){
      soma += 1.0/(j+1.0);  
      j += 1.0;
      //printf("%lf\n", soma);
    }
    printf("%.6lf\n", soma);
  }
  else{
    printf("Numero invalido!\n");
  }

  return 0;
}
