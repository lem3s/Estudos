#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX 10000

int main(){

  int n, letras=0, vogais=0, consoantes=0, i=0, j=0;
  char str[MAX];

  scanf("%d", &n);
  getchar();

  for(i=0; i<n; i++){
    fgets(str, MAX, stdin);

    for(j=0; j<strlen(str); j++){
      if(isalpha(str[j])){
        letras++;

        if(toupper(str[j]) == 'A' || toupper(str[j]) == 'E' || toupper(str[j]) == 'I' || toupper(str[j]) == 'O' || toupper(str[j]) == 'U'){
          vogais++;
        }else{
          consoantes++;
        }
      }
    }

    printf("Letras = %d\n", letras);
    printf("Vogais = %d\n", vogais);
    printf("Consoantes = %d\n", consoantes);

    letras = 0;
    vogais = 0;
    consoantes = 0;
  }


  return 0;
}
