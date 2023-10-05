#include <math.h>
#include <stdio.h>

int main(){
  float x1, y1, x2, y2, res;
  scanf("%f", &x1);
  scanf("%f", &y1);
  scanf("%f", &x2);
  scanf("%f", &y2);
  
  res = sqrt(pow(x1-x2, 2) + (pow(y1-y2, 2)));

  printf("A DISTANCIA ENTRE A e B = %.2f\n", res);
  return 0;
}
