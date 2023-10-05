#include <stdio.h>

int main(){

  int n;
  double spares, simpares, ipares, iimpares;

  while(1){
    scanf("%d", &n);
    if (n == 0){
      break;
    }else if(n%2 == 0){
      spares += n;
      ipares++;
    }else if(n%2 != 0){
      simpares += n;
      iimpares++;
    } 
  }

  printf("MEDIA PAR: %.6lf\nMEDIA IMPAR: %.6lf\n", spares/ipares, simpares/iimpares);

  return 0;
}
