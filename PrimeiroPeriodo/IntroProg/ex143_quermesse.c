#include <stdio.h>

int achaSorteado(int arr[], int n);

int main(){
  int n, i=0, j=1;; 
  int arr[200];

  while(1){
    scanf("%d", &n);

    if(n == 0){
      return 0;
    }

    for(i=0; i<n; i++){
      scanf("%d", &arr[i]);
    }

    printf("Teste %d\n%d\n", j, achaSorteado(arr, n));

    j++;
  }


  return 0;
}

int achaSorteado(int arr[], int n){
  int i=0;

  for(i=1; i<=n; i++){
    if(arr[i] == i){
      break;
    }
  }
  return i;
}
