#include <stdio.h>

int main(){
  int n, m, s, numero, flag, n1, n2, n3, n4, n5, soma;
  scanf("%d", &n);
  scanf("%d", &m);
  scanf("%d", &s);
  
  numero = m;
  flag = 0;

  while (flag == 0){
    if (numero == 10000){
      soma = 10000;
    }
    if ((numero < 10000) && (numero >= 1000)){
      n1 = numero / 1000;
      n2 = (numero%1000) / 100;
      n3 = (numero%100) / 10;
      n4 = numero%10;
      soma = n1 + n2 + n3 + n4;
    }
    if ((numero < 1000) && (numero >= 100)){
      n1 = numero / 100;
      n2 = (numero%100) / 10;
      n3 = numero%10;
      soma = n1 + n2 + n3;
    }
    if ((numero < 100) &&(numero >= 10)){
      n1 = numero / 10;
      n2 = numero%10;
      soma = n1 + n2;
    }
    if (numero < 10){
      n1 = numero;
      soma = n1;
    }
    if ((numero >= n) && (soma == s)){
	    flag = 1;
    }else if (numero < n){
	    flag = 1;
	    numero = -1;
    }else{
      numero--;
    }
  }
  printf("%d\n", numero);
  return 0;
}
