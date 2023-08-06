#include <stdio.h>

int main(){
  double i=0;
  double valIni, valBase, valFin;
  double valIng, quant, lucro;
  double melLucro=0, melhorVal=0, numIngressos=0;

  scanf("%lf", &valBase);
  scanf("%lf", &valIni);
  scanf("%lf", &valFin);

  if(valIni >= valFin){
    printf("INTERVALO INVALIDO.\n");
    return 0;
  }

  for(i=valIni; i<=valFin; i++){
    if(i < valBase){
      quant = 120 + ((valBase - i)/0.5) * 25;
    }
    else if(i == valBase){
      quant = 120;
    }
    else if(i > valBase){
      quant = 120 - ((i - valBase)/0.5) * 30;
    }

    lucro = (quant * i) - 200 - (0.05 * quant);

    printf("V: %.2lf, N: %.0lf, L: %.2lf\n", i, quant, lucro);

    if(lucro > melLucro){
      melLucro = lucro;
      melhorVal = i;
      numIngressos = quant;
    }
  }

  printf("Melhor valor final: %.2lf\n", melhorVal);
  printf("Lucro: %.2lf\n", melLucro);
  printf("Numero de ingressos: %.0lf\n", numIngressos);

  return 0;
}
