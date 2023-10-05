#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(){

  int n, f1, f2, i=0, flag=0;
  
  scanf("%d %d %d", &n, &f1, &f2);
  int fibo[n];
  int arr[n];
  fibo[0] = f1;
  fibo[1] = f2;
  
  for(i=2; i<n; i++){
    fibo[i] = fibo[i-1] + fibo[i-2];
  }

  for(i=0; i<n; i++){
    scanf("%d", &arr[i]);
  }

  for(i=0; i<n; i++){
    if(arr[i] == fibo[i]){
      printf("OK\n");
    }else{
      printf("Nao e Fibonacci\n");
      flag = 1;
      break;
    }
  }

  if(flag == 0){
    printf("A serie informada e de Fibonacci\n");
  }

  return 0;
}
