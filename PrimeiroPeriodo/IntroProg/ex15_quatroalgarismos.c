#include <stdio.h>

int main(){
  int input, n1, n2 , n3, res;
  
  scanf("%d", &input);

  n1 = input/100;
  n2 = (input%100)/10;
  n3 = input%10;
  
  res= (n1+n2*3+n3*5)%7;

  printf("O NOVO NUMERO E = %d%d\n", input, res);

  return 0;
}
