#include <stdio.h>

int main(){

  int n, i=0, pv, sv, comprimento=1, maior_comp=1;
  
  scanf("%d", &n);
  scanf("%d", &pv);
  
  for(i=0; i<n-1; i++){
    scanf("%d", &sv);
    if(sv > pv){
      comprimento ++; 
      if (comprimento > maior_comp){
        maior_comp = comprimento;
      }
    }else{
      comprimento = 1;
    }
    pv = sv;
  }
  printf("O comprimento do segmento crescente maximo e: %d\n", maior_comp);

  return 0;
}
