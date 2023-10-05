#include <stdio.h>
#include <string.h>
#include <ctype.h>


int main(){

  char numSeq[10];
  int codUF, dv1, dv2, j, soma=0, i=0;
  
  scanf("%s %d", numSeq, &codUF);

  if(codUF <= 28){
   
    //printf("strlen(numSeq)=%ld\n", strlen(numSeq));
    j=strlen(numSeq)-1;
    //printf("j=%d\n", j);
    for(i=9; i>9 - strlen(numSeq); i--){
      soma += (numSeq[j]-'0')*i;
      //printf("soma=%d numSeq*i=%d\n",soma, numSeq[j]*i); 
      j--;
    }   
    dv1 = soma%11;
    if(dv1 == 10){
      dv1 = 0;
    }

    if(codUF < 10){
      dv2 = (codUF * 8)%11;
      if(dv2 == 10){
        dv2 = 0;
      }
    }else{
      int n1, n2;

      n1 = codUF/10;
      //printf("n1 = %d\n", n1);
      n2 = codUF%10;
      //printf("n2 = %d\n", n2);

      dv2 = ((n1*7) + (n2*8) + (dv1*9))%11;
      if(dv2 == 10){
        dv2 = 0;
      }
    }

    printf("%s", numSeq); 

    if(codUF < 10){
      printf("0");
    }
    printf("%d/%d%d\n", codUF, dv1, dv2);

  }else{
    printf("CODIGO DA UF INVALIDO!\n");
  }

  return 0;
}

