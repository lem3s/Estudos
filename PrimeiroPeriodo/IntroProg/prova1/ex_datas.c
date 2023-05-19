#include <stdio.h>

int main(){
  int dia, mes, ano, bi = 0;

  scanf("%d %d %d", &dia, &mes, &ano);
    
  if ((ano%4 == 0) && (ano%100 != 0)){
    bi = 1;
    printf("bi recebe 1");
  }
  if (ano == 2000){
    bi =1;
  }

  //28 - 2
  //30 - 4, 6, 9, 11
  //31 - 1, 3, 5, 7, 8, 10, 12


  if ((ano < 1900) || (ano > 2036)){
    printf("DATA FORA DO INTERVALO ESTIPULADO\n");
  }else if ((bi == 0) && (mes == 2) && (dia > 28)){
    printf("DATA INVALIDA1\n");
  }else if(((mes == 1) || (mes == 3) || (mes == 5) || (mes == 7) || (mes == 8) || (mes == 10) || (mes == 12)) && (dia > 31)){
    printf("DATA INVALIDA2\n");
  }else if(((mes == 4) || (mes == 6) || (mes == 9) || (mes == 11)) && (dia > 30)){
    printf("DATA INVALIDA3\n");
  }else if((mes == 2) && (dia > 28) && (bi == 0)){
    printf("DATA INVALIDA4\n");
  }else{
    printf("%d/%d/%d\n", dia, mes, ano);
  }
  
  return 0;
}
