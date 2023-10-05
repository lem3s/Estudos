#include <stdio.h>

int main(){
  double massa, acel, tempo, vel, velkm, s, trab;
  scanf("%lf", &massa);
  scanf("%lf", &acel);
  scanf("%lf", &tempo);

  vel = (acel * tempo);
  velkm = vel * 3.6;
  s = acel * (tempo*tempo)/2;
  trab = (massa*1000) * (vel*vel)/2;

  printf("VELOCIDADE = %.2lf\n", velkm);
  printf("ESPACO PERCORRIDO = %.2lf\n", s);
  printf("TRABALHO REALIZADO = %.2lf\n", trab);
  
  return 0;
}
