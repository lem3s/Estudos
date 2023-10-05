#include <stdio.h>

int main(){

  int n, v1, v2, i=0, comp=1, maior_comp=1;

  scanf("%d", &n);
  scanf("%d", &v1);

  for (i=0; i<n-1; i++){
    scanf("%d", &v2);
    if (v1==v2){
      comp++;
        if (comp > maior_comp){
          maior_comp = comp;
        }
    }else{
      comp = 1;
    }
    v1 = v2;
  }
  printf("O comprimento do segmento de numeros iguais e: %d\n", maior_comp);

  return 0;
}
