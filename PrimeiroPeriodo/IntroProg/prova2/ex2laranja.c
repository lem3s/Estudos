#include <stdio.h>

int main(){

  long int n1, n2, n3, n4, soma;

  scanf("%ld %ld %ld %ld", &n1, &n2, &n3,&n4);

  if (n1 > n2 && n1 > n3 && n1 > n4){
    soma = n2 + n3 + n4;
  }else if (n2 > n1 && n2 > n3 && n2 > n4){
    soma = n1 + n3 + n4;
  }else if (n3 > n1 && n3 > n2 && n3 > n4){
    soma = n1 + n2 + n4;
  }else if (n4 > n1 && n4 > n2 && n4 > n3){
    soma = n1 + n2 + n3;
  }else{
    soma = n2 + n3 + n4;
  }

  printf("%ld\n", soma);

  return 0;
}
