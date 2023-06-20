#include <stdio.h>

int main(){

  int n, tam=0, res, resto, i=0, temp;
  int bin[32];

  for(i=0; i<32; i++){
    bin[i] = 0;
  }
  i=0;

  while(1){
    scanf("%d", &n);

    if(n == 0){
      printf("0\n");

    }else{
      while(n != 0){
        bin[i] = n%2;
        i++;
        n = n/2;
      }
      tam=i-1;

      for(i=0; i<tam; i++){
        printf("%d", bin[tam-i]);
      }

      printf("\n");

      /*
      for(i=0; i<32; i++){
        printf("%d", bin[i]);
      }
      printf("\n");
      */

      i=0;
    }
    
  }




  return 0;
}
