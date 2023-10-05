#include <stdio.h>

int main(){
  double a, b, c, d, e, f, x, y;
  scanf("%lf", &a);
  scanf("%lf", &b);
  scanf("%lf", &c);
  scanf("%lf", &d);
  scanf("%lf", &e);
  scanf("%lf", &f);

  y = (c - (f * (a/d))) / (b - (e *(a/d)));
  x = (f - e * y) / d;

  printf("O VALOR DE X E = %.2lf\n", x);
  printf("O VALOR DE Y E = %.2lf\n", y);

  return 0;
}
