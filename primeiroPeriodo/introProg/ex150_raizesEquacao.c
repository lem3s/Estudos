#include <stdio.h>
#include <math.h>

int raizesEq2Grau(double a, double b, double c);

int main(){
  double a, b, c, x1, x2, delta;
  scanf("%lf %lf %lf", &a, &b, &c);
  
  delta = (b*b) - 4 * a * c;

  if (raizesEq2Grau(a, b, c) == 0){
    printf("RAIZES IMAGINARIAS\n");
  }else if(raizesEq2Grau(a, b, c) == 1){
    x1 = (b * -1)/(2*a);
    printf("RAIZ UNICA\n");
    printf("X1 = %.2lf\n", x1);
  }else if(raizesEq2Grau(a, b, c) == 2){
    x1 = ((b * -1) - sqrt(delta))/( 2 * a);
    x2 = ((b * -1) + sqrt(delta))/( 2 * a);
    printf("RAIZES DISTINTAS\n");
    printf("X1 = %.2lf\n", x1);
    printf("X2 = %.2lf\n", x2);
  }

  return 0;
}

int raizesEq2Grau(double a, double b, double c){
  int delta = (b*b) - 4 * a * c;

  if (delta < 0){
    return 0;
  }else if(delta == 0){
    return 1;
  }
  return 2;
}
