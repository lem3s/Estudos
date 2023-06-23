#include <stdio.h>

int main(){

  int n, i=0, maior=0, indexMaior=0, contador=0;

  scanf("%d", &n);
  int arr[n];

  for(i=0; i<n; i++){
    scanf("%d", &arr[i]);
    if(arr[i] > maior){
      maior = arr[i];
      indexMaior = i;
    }
  }
  
  for(i=0; i<n; i++){
    if(arr[i] == arr[n-1]){
      contador++;
    }
  } 
   
  printf("Nota %d, %d vezes\n", arr[n-1], contador);
  printf("Nota %d, indice %d", maior, indexMaior);

  return 0;
}
