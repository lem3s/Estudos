#include <stdio.h>

int main(){
  int h, m, s, res;
  scanf("%d", &h);
  scanf("%d", &m);
  scanf("%d", &s);

  res = h*3600 + m * 60 + s;

  printf("O TEMPO EM SEGUNDOS E = %d\n", res);

  return 0;
}
