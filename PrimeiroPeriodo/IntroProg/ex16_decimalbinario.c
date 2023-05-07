#include <stdio.h>

int main(){
  int num, resultado;
  char bin[] = "00000000";
  int i = 7;

  scanf("%d", &num);
  resultado = 1;

  if ((0<=num) && (num<=255)){
    while (resultado != 0){
      resultado = num / 2;
      bin[i] = (num % 2) + '0';
      num = resultado;
      i--;
    }
    printf("%s\n", bin);
  }else{
    printf("Numero invalido!\n");
  }
  return 0;
}
