#include <stdio.h>

int main(){

  int n, k, contador=0, i=0;

  scanf("%d %d", &n, &k);
  int arr[n];

  for(i=0; i<n; i++){
    scanf("%d", &arr[i]);
  } 

  for(i=0; i<n; i++){
    if(arr[i] <= 0){
      contador++;
    }
  }

  if(contador < k){
    printf("SIM\n");
  }else{
    printf("NAO\n");
  }
  
  return 0;
}
