#include <stdio.h>

int main(){

  int n, i=0, j;

  scanf("%d", &n);

  int arr[n], inv[n];

  for(i=0; i<n; i++){
    scanf("%d", &arr[i]);
  }

  j=n-1;
  for(i=0; i<n; i++){
    inv[i] = arr[j];
    j--;
  }

  for(i=0; i<n; i++){
    printf("%d ", inv[i]);
  }
  printf("\n");

  return 0;
}
