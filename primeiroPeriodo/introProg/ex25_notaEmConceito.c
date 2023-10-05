#include <stdio.h>

int main(){
  float nota;
  char conceito;

  scanf("%f", &nota);
  
  if (nota >= 9){
    conceito = 'A';
  }
  if ((nota >= 7.5) && (nota < 9)){
    conceito = 'B';
  }
  if ((nota >= 6) && (nota < 7.5)){
    conceito = 'C';
  }
  if ((nota < 6)){
    conceito = 'D';
  }

  printf("NOTA = %.1f CONCEITO = %c\n", nota, conceito);

  return 0;
}
