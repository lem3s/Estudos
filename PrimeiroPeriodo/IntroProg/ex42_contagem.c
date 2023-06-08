#include <stdio.h>

int main(){

  int n, k, i=0, contador=0;

  scanf("%d", &n);
  int arr[n];

  for(i=0; i<n; i++){
    scanf("%d", &arr[i]);
  }

  scanf("%d", &k);

  for(i=0; i<n; i++){
    if(arr[i] >= k){
      contador++;
    }
  }

  printf("%d\n", contador);

  return 0;
}
