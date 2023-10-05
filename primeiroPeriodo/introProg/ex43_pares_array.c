#include <stdio.h>

int main(){

  int n, i=0, tot=0, j=0;

  scanf("%d", &n);
  int arr[n], pares[n];

  for(i=0; i<n; i++){
    scanf("%d", &arr[i]);
  }

  for(i=0; i<n; i++){
    if(arr[i] % 2 == 0){
      pares[j] = arr[i];
      tot++;
      j++;
    }
  }

  if(tot > 0){
    for(i=0; i<tot; i++){
      printf("%d ", pares[i]);
    }
  }
  printf("%d\n", tot);


  return 0;
}
