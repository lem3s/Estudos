#include <stdio.h>

void decToBin(int numDec, int i, int aux[]);

int main(void){
  int n, i;

  scanf("%d", &n);

  int arr[n];

  for (i = 0; i < n; i++){
    scanf("%d", &arr[i]);
  }

  int aux[100];
  for (i = 0; i < n; i++){
    decToBin(arr[i], 0, aux);
  }

  return 0;
}

void decToBin(int numDec, int i, int aux[]){
  if(numDec == 0){
    unsigned long long res = 0;

    i = i - 1;
    for (; i >= 0; i--){
      printf("%d", aux[i]);

    }
    printf("\n");

    return;
  }

  aux[i] = numDec % 2;

  return decToBin(numDec / 2, i+= 1, aux);
}
