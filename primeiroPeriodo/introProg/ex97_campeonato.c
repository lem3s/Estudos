#include <stdio.h>

int main(){
   
  int n, tot_jogos, i=0, j=0, k=1, contador=1;

  scanf("%d", &n);
  
  tot_jogos = (n*(n-1))/2;

  for(i=0; i<n-1; i++){
    for(j=0; j<n-k; j++){
      printf("Final %d: Time%d X Time%d\n", contador, i+1, i+1+j+1);
      contador++;
    }
    k++;
  }

  return 0;
}
