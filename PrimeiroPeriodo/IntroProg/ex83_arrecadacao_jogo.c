#include <stdio.h>

int main(){
  
  int n, i=0, pessoas;
  double ppop, pger, parq, pcad, tot;

  scanf("%d", &n);

  for(i=0; i < n; i++){
    scanf("%d %lf %lf %lf %lf", &pessoas, &ppop, &pger, &parq, &pcad); 
    tot = pessoas * ((ppop/100) * 1) + pessoas * ((pger/100) * 5) + pessoas * ((parq/100) * 10) + pessoas * ((pcad/100) * 20);
    printf("A RENDA DO JOGO N.%d E = %.2f\n", i+1, tot);
  }

  return 0;
}
