#include <stdio.h>
#include <math.h>

unsigned long long decToBin(int numDec, int i, int aux[]);

int main(void){
  int n, i;

  scanf("%d", &n);

  int arr[n];

  for (i = 0; i < n; i++){
    scanf("%d", &arr[i]);
  }

  int aux[100];
  for (i = 0; i < n; i++){
    printf("%lld\n", decToBin(arr[i], 0, aux));
  }

  return 0;
}

unsigned long long decToBin(int numDec, int i, int aux[]){
  if(numDec == 0){
    unsigned long long res = 0;

    i = i - 1;
    for (; i >= 0; i--){
      res +=  aux[i] * pow(10, i);
      // printf("# RES %d\n", res);
    }

    return res;
  }

  aux[i] = numDec % 2;
  // printf("# AUX[%d] %d\n", i, aux[i]);

  return decToBin(numDec / 2, i+= 1, aux);
}
