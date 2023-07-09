#include <stdio.h>

int main(){

  int l, c, cor, i=0, j=0;

  scanf("%d", &l);
  scanf("%d", &c);

  for(i=1; i<=l; i++){

    if(i%2 == 0){
      for(j=1; j<=c; j++){
        if(j%2 == 0){
          printf("1");
        }else{
          printf("0");
        }
      }
    }

    if(i%2 != 0){
      for(j=1; j<=c; j++){
        if(j%2 == 0){
          printf("0");
        }else{
          printf("1");
        }
      }
    }

    printf("\n");
  }



}
