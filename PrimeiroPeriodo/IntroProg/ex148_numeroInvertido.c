#include <stdio.h>
#include <string.h>

void separaDigitos();

int main(){
    separaDigitos(); 

  return 0;
}

void separaDigitos(){
  char str[5];

  fgets(str, sizeof(str), stdin);

  printf("%c%c%c\n", str[2], str[1], str[0]);

};
