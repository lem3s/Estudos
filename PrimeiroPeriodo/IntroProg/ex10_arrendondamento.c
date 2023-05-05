#include <stdio.h>

int main(){
  float input, numfra;
  int numint;

  scanf("%f", &input);

  numint = input * 10 + 0.5;
  numfra = numint/10.0;
  printf("%.6f\n", numfra);

  numint = input * 100 + 0.5;
  numfra = numint/100.0;
  printf("%.6f\n", numfra);

  numint = input * 1000 + 0.5;
  numfra = numint/1000.0;
  printf("%.6f\n", numfra);

  return 0;
}
