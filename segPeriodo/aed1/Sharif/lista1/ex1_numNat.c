#include <stdio.h>

void nums(int n);

int main(void){
  int n;

  scanf("%d", &n);

  nums(n);

  printf("\n");

  return 0;
}

void nums(int n){
  n--;
  
  if (n > 0){
    nums(n);
  }
   
  printf("%d ", n+1);
}
