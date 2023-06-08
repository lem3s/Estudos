#include <stdio.h>

int main(){

  int n, i=0;

  scanf("%d", &n);
  int arr[n];

  for(i=0; i<n; i++){
    scanf("%d", &arr[i]);
  }

  for(i=0; i<n; i++){
    printf("%d ", arr[i]);
  }

  printf("\n");

  return 0;
}
