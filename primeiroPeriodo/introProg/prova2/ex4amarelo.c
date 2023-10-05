#include <stdio.h>

int main(){

  int n, i=0, j=0, k=1, contador=1;

  scanf("%d", &n);

  for(i=0; i<n-1; i++){
    for(j=0; j<n-k; j++){
      if (i+1+j+1 < n){
        printf("(%d,%d)-", i+1, i+1+j+1);
      }else if (i+1+j+1 == n){
        printf("(%d,%d)\n", i+1, i+1+j+1);
      }
    }
    k++;
  }

  return 0;
}


