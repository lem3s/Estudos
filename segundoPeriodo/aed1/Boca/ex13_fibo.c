#include <stdio.h>

unsigned long long int fibo(int x);

int main(void){
  int n, i;

  scanf("%d", &n);
  int arr[n];

  for (i=0; i < n; i++){
    scanf("%d", &arr[i]);
  }

  for (i=0; i < n; i++){
    printf("%llu\n", fibo(arr[i]));
  }

  return 0;
}

unsigned long long int fibo(int x){
  unsigned long long int n1 = 0, n2 = 1, temp;
  int i;

  for (i=1; i < x; i++){
    temp = n2;
    n2 += n1;
    n1 = temp;
  }

  return n2;
}
