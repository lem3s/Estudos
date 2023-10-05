#include <stdio.h>
#include <string.h>

int main(){

  int n, size, contador=0, i=0;
  char str[1010];
  char aux;

  scanf("%d", &n);
  getchar();

  for(contador=0; contador<n; contador++){

    fgets(str, 1000, stdin);

    size = strlen(str) - 1;

    for(i=0; i<size; i++){
      //Verifica alfanumerico
      if((str[i] >= 65 && str[i] <= 90) || (str[i] >= 97 && str[i] <= 122) || (str[i] >= 48 && str[i] <= 57)){
        str[i] += 3;
      }
    }

    if(size%2 == 0){
      for(i=0; i<size; i+=2){
        aux = str[i];
        str[i] = str[i+1];
        str[i+1] = aux;
      }
    }else{
      for(i=0; i<size-1; i+=2){
        aux = str[i];
        str[i] = str[i+1];
        str[i+1] = aux;
      }
    }

    for(i=0; i<size; i++){
      if(str[i] == ' '){
        str[i] = '+';
      }else if(str[i] == '+'){
        str[i] = ' ';
      }
    }

    printf("%s", str);

  }
  printf("\n");
  return 0;
}
