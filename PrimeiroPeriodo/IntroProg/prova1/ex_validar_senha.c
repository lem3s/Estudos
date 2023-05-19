#include <stdio.h>

int main(){
  char cat;
  int senha;
  int senha_adm = 321456;
  int senha_ger = 9510753;
  int senha_user = 78955632;

  scanf("%d %c", &senha, &cat);

  if (cat != 'A' && cat != 'G' && cat != 'U'){
    printf("CATEGORIA INVALIDA: %c\n", cat);
  }else if(senha < 100000){
    printf("SENHA INVALIDA: %d - MINIMO 6 DIGITOS\n", senha);
  }else if (cat == 'A' && senha != senha_adm){
    printf("ACESSO NEGADO\n");
  }else if (cat == 'G' && senha != senha_ger){
    printf("ACESSO NEGADO\n");
  }else if (cat == 'U' && senha != senha_user){
    printf("ACESSO NEGADO\n");
  }else{
    printf("ACESSO PERMITIDO A CATEGORIA %c\n", cat);
  }

  return 0;
}
