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
  int grau = 10;

  if(cc >= MAX_CC){
    grau--;
  }
  if(dr <= MIN_DR){
    grau--;
  }
  if(rt <= MIN_RT){
    grau--;
  }

  return grau;
}
