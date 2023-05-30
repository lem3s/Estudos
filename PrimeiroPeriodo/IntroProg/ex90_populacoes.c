#include <stdio.h>

int main(){

  float a, b;
  int n = 0;

  scanf("%f", &a);
  scanf("%f", &b);


  while(a < b){
   a = a * 1.03;
   b = b * 1.015;

    n++;
  }

  printf("ANOS = %d\n", n); 

  return 0;
}
