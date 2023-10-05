#include <stdio.h>

int main(){

  int n, i=2, primo=1;

  scanf("%d", &n);

  if(n < 0){
    printf("Numero invalido!\n");
  }else{
    for(i=2; i<n; i++){
      if(n%i == 0){
        primo = 0;
      }
    }
    if(primo == 1 && n != 1 && n != 0){
      printf("PRIMO\n");
    }else{
      printf("NAO PRIMO\n");
    }
  }

  return 0;
}
