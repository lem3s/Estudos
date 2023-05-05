#include <stdio.h>
#include <math.h>

int main(){
  float l1, l2, l3, t, a;
  
  scanf("%f", &l1);
  scanf("%f", &l2);
  scanf("%f", &l3);

  t = (l1 + l2 + l3)/2;

  a = sqrt(t*(t-l1) * (t-l2) * (t-l3));

  printf("A AREA DO TRIANGULO E = %.2f\n", a);

  return 0;
}
