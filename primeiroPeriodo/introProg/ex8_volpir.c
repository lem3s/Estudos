#include <stdio.h>

int main(){
  float h, aresta, area, volume;
  scanf("%f", &h);
  scanf("%f", &aresta);

  area = (3 * (aresta*aresta) * 1.73205)/2;
  volume = (area * h)/3;

  printf("O VOLUME DA PIRAMIDE E = %.2f METROS CUBICOS\n", volume);
  
  return 0;
}
