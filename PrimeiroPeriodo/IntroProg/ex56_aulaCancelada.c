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
    for(i=n-1; i>=0; i--){
      if(arr[i]<=0){
        printf("%d\n", i+1);
      }
    }
  }
  

  return 0;
}
