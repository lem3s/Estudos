#include <stdio.h>

int main(void){

  int n, i, j;

  scanf("%d", &n);

  int arr[n];

  for (i=0; i < n; i++){
    scanf("%d", &arr[i]);
  }

  int flag = 0;
  for (i=0; i < n; i++){
    for (j=2; j < arr[i]; j++){
      if (arr[i] % j == 0){
        flag = 1;
        break;
      }
    }    
    if (flag == 0){
      printf("primo\n");
    }
    else{
      printf("composto\n");
    }

    flag = 0;
  }

  return 0;
}
