#include <stdio.h>

int main(){

  int n, i=0, j=0, contador=0;

  scanf("%d", &n);
  int arr[n];

  for(i=0; i<n; i++){
    scanf("%d", &arr[i]);
  } 

  for(i=0; i<n; i++){
    for(j=0; j<n; j++){
      if(i != j && arr[i] == arr[j]){
        contador++;
        break;
      }
    }
  }

  printf("%d\n", n-contador); 

  return 0;
}
