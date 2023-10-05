#include <stdio.h>

int main(){

  int n, i=0, soma=0;

  scanf("%d", &n);
  int arr[n];

  for(i=0; i<n; i++){
    scanf("%d", &arr[i]);
  }

  for(i=0; i<n; i++){
    soma += arr[i];
  }

  printf("%d\n", soma);

  return 0;
}
