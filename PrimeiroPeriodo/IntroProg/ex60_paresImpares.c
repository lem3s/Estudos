#include <stdio.h>

void bubbleCrescente(int arr[], int n){
  int i=0, j=0, temp;

  for(i=0; i<n-1; i++){
    for(j=0; j<n-1-i; j++){
      if(arr[j] > arr[j+1]){
        temp = arr[j];
        arr[j] = arr[j+1];
        arr[j+1] = temp;
      }
    }
  }
}

void bubbleDerescente(int arr[], int n){
  int i=0, j=0, temp;

  for(i=0; i<n-1; i++){
    for(j=0; j<n-1-i; j++){
      if(arr[j] < arr[j+1]){
        temp = arr[j];
        arr[j] = arr[j+1];
        arr[j+1] = temp;
      }
    }
  }
}

int main(){

  int n, i=0, temp, quantPares=0, quantImpares=0;

  scanf("%d", &n);
  int pares[n];
  int impares[n];

  for(i=0; i<n; i++){
    scanf("%d", &temp);

    if(temp%2 == 0){
      pares[quantPares] = temp;
      quantPares++;
    }
    else{
      impares[quantImpares] = temp;
      quantImpares++;
    }
  } 

  bubbleCrescente(pares, quantPares);
  bubbleDerescente(impares, quantImpares);

  for(i=0; i<quantPares; i++){
    printf("%d\n", pares[i]);
  }
  for(i=0; i<quantImpares; i++){
    printf("%d\n", impares[i]);
  }

  return 0;
}
