#include <stdio.h>

int main(){

  int n, res = 0, j;

  scanf("%d", &n);

  int i = n;
  for(i=n; i > 0; i--){
    if(i==n){
      res = i;
    }else{
      res = res * i;
    }
  }

  printf("%d! =  %d\n", n, res);

  return 0;
}
