#include <stdio.h>

int n0 = 0, n1 = 1;

void fibo(int x);

int main(void){
  int n;

  scanf("%d", &n);

  if (n == 0){
    printf("0");
  }
  else if (n == 1){
    printf("0 1");
  }
  else{
    printf("0 1 ");
    fibo(n);
  }

  printf("\n");

  return 0;
}

void fibo(int x){
  if (x < 2){
    return;
  }
  int temp = n1;
  n1 += n0;
  n0 = temp;
  printf("%d ", n1); 

  fibo(x - 1);
}
