#include <stdio.h>

#define MAX_CC 7
#define MIN_DR 50
#define MIN_RT 80000

int grauAco(int cc, int dr, int rt);

int main(){
  int cc, dr, rt;

  scanf("%d", &cc);
  scanf("%d", &dr);
  scanf("%d", &rt);
 
  printf("ACO DE GRAU = %d\n", grauAco(cc, dr, rt));

  return 0;
}

int grauAco(int cc, int dr, int rt){
  int grau;

  if(cc < MAX_CC && dr > MIN_DR){
    grau=9;
  }
  else if(cc < MAX_CC && dr < MIN_DR && rt < MIN_RT){
    grau=8;
  }
  else if(cc > MAX_CC && dr < MIN_DR && rt < MIN_RT){
    grau=7;
  }
  else{
    grau=10;
  }

  return grau;
}
