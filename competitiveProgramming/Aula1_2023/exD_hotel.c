#include <stdio.h>

int main(){
  int d, a, n, diaria, total;
  scanf("%d", &d);
  scanf("%d", &a);
  scanf("%d", &n);

  if (n > 15){
    diaria = (d + (14 * a));
    total = diaria * (32 - n);
  }else{
    diaria = d + ((n - 1) * a);
    total = diaria * (32 - n);
  }
  printf("%d\n", total);
  
  return 0;
}
