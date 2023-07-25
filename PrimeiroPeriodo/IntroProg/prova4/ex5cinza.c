#include <stdio.h>

int main(){
  int n, anterior, i=0;

  scanf("%d", &n);
  int arr[n];
  
  for(i=0; i<n; i++){
    scanf("%d", &arr[i]);
  }

  for(i=0; i<n; i++){
    if(i==0){
      printf("%d\n", arr[i]);
      anterior = arr[i];
    }
    else if (anterior != arr[i]){
      printf("%d\n", arr[i]);
      anterior = arr[i];
    }
  }

  return 0;
}
