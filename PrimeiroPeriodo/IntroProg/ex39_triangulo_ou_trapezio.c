#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){

  float a, b, c;

  scanf("%f %f %f", &a, &b, &c);

  if ((a > fabs(b - c)) && (a < b+c) && (b > fabs(a - c)) && (b < a+c) && (c > fabs(a - b)) && (c < a+b)){
    printf("Perimetro = %.1f\n", a + b +c);
  }else{
    printf("Area = %.1f\n", (a + b)*c/2);
  }

  return 0;
}
