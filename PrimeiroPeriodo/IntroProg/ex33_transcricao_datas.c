#include <stdio.h>

int main(){
  int data;
  scanf("%d", &data);

  int dia = data/1000000;
  int mes = (data%1000000)/10000;
  int ano = data%10000;

  printf("%d\n", dia);
  printf("%d\n", mes);
  printf("%d\n", ano);
  return 0;
}
