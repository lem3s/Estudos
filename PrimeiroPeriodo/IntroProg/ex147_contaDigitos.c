#include <stdio.h>
#include <string.h>

int digit_count(long int n);

int main(){

  long int n;

  scanf("%ld", &n);

  printf("Numero de digitos: %d\n", digit_count(n));

  return 0;
}

int digit_count(long int n){
  char str[10000];

  sprintf(str, "%ld", n);

  return strlen(str);
}
