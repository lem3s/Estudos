#include <stdio.h>

unsigned long long int fibo(int x);

int main(void){
  int k, i, j;

  scanf("%d", &k);
  int arr[k];

  for (i=0; i < k; i++){
    scanf("%d", &arr[i]);
  }

  for (i=0; i < k; i++){
    unsigned long long int res = fibo(arr[i]);

    //printf("%llu : ", res);

    do{
      for (j = 2; j <= res; j++){
        if (res % j == 0){
          printf("%d ", j);
          res = res / j;
          break;
        }
      } 
    } while(j != res * j);

    printf("\n");
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
