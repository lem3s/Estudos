#include <stdio.h>

int main(){

  int n, i=0, maior=0, soma=0, j=0;
  int arr[10010];

  while(1){
    scanf("%d", &n);

    if(n == 0){
      break;
    }

    for(i=0; i<n; i++){
      scanf("%d", &arr[i]);
    }

    for(i=0; i<n; i++){
      if(arr[i] > maior){
        maior = arr[i];
      }
    }

    for(i=0; i<=maior; i++){
      for(j=0; j<n; j++){
        if(arr[j] == i){
          soma++;
        }
      }
      printf("(%d) %d\n", i, soma);
    }

    soma=0;
    maior = 0;
  }
















  return 0;
}
