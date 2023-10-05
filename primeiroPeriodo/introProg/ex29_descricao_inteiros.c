#include <stdio.h>
#include <string.h>

int main(){
	int num, un_milhar, centena, dezena, unidade;
  char s[] = "s";
  char plural_un_milhar[2] = "";
  char plural_centena[2] = "";
  char plural_dezena[2] = "";
  char plural_unidade[2] = "";
  scanf("%d", &num);

	if ((num >= 1000) && (num < 10000)){
		un_milhar = num/1000;
		centena = (num % 1000) / 100;
		dezena = (num % 100) / 10;
		unidade = num % 10;
    if (un_milhar > 1){
      strcpy(plural_un_milhar, s);
    }
    if (centena > 1){
      strcpy(plural_centena, s);
    }  
    if (dezena > 1){
      strcpy(plural_dezena, s);
    }  
    if (unidade > 1){
      strcpy(plural_unidade, s);
    }  

    printf("(quarta ordem) %d = %d unidade%s de milhar + %d centena%s + %d dezena%s + %d unidade%s = %d + %d + %d + %d\n", num, un_milhar, plural_un_milhar, centena, plural_centena, dezena, plural_dezena, unidade, plural_unidade, un_milhar*1000, centena*100, dezena*10, unidade);

	} else if ((num >= 100) && (num < 1000)){
		centena = num / 100;
		dezena = (num % 100) / 10;
		unidade = num % 10;
		
    if (centena > 1){
      strcpy(plural_centena, s);
    }  
    if (dezena > 1){
      strcpy(plural_dezena, s);
    }  
    if (unidade > 1){
      strcpy(plural_unidade, s);
    }  

    printf("(terceira ordem) %d = %d centena%s + %d dezena%s + %d unidade%s = %d + %d + %d\n", num, centena, plural_centena, dezena, plural_dezena, unidade, plural_unidade, centena*100, dezena*10, unidade);

	} else if ((num >= 10) && (num < 100)){
		dezena =  num / 10;
		unidade = num % 10;
  
    if (dezena > 1){
      strcpy(plural_dezena, s);
    }  
    if (unidade > 1){
      strcpy(plural_unidade, s);
    }  

    printf("(segunda ordem) %d = %d dezena%s + %d unidade%s = %d + %d\n", num, dezena, plural_dezena, unidade, plural_unidade, dezena*10, unidade);

	}else if ((num >= 0) && (num < 10)){
		unidade = num;
		
    if (unidade > 1){
      strcpy(plural_unidade, s);
    }  

    printf("(primeira ordem) %d = %d unidade%s = %d\n", num, unidade, plural_unidade, unidade);

	}else {
		printf("Numero invalido!\n");
	}

	return 0;
}
