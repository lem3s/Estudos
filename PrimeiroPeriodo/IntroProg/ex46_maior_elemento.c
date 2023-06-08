#include <stdio.h>

int main(){

  int n, i=0, maior=-1, pos=0;
  int arr[1010]; 

  while(1){
    scanf("%d", &n);

    if(n == 0){
      break;
    }

    for(i=0; i<n; i++){
      scanf("%d", &arr[i]);
    }

    for(i=0; i<n; i++){
      if(arr[i] > maior){
        maior = arr[i];
        pos = i;
      }
    }
  
    printf("%d %d\n", pos, maior);

    maior=-1;
    pos=0;
  }


  return 0;
}
