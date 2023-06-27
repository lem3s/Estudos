#include <stdio.h>
#include <string.h>

int procura(char c, char str[]);

int main(){

  int n, index, i=0;
  char str[510];

  scanf("%d", &n);
  getchar();

  for(i=0; i<n; i++){
    fgets(str, sizeof(str), stdin);

    index = procura(str[0], str);

    if(index > 0){
      printf("Caractere %c encontrado no indice %d da string.\n", str[0], index);
    }else{
      printf("Caractere %c nao encontrado.\n", str[0]);
    }
  }

  return 0; 
}

int procura(char c, char str[]){
  int res=-1, i=0;
  
  for(i=2; i<strlen(str); i++){
    if(str[i] == c){
      res = i-2;
      break;
    }
  } 

  return res;
}
