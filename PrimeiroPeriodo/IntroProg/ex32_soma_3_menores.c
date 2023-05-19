#include <stdio.h>

int main(){
  int valores[4];
  int i=0, j=0, temp=0, soma=0;

  for(i = 0; i < 4; i++){
    scanf("%d", &valores[i]);
  }

  for (int i=0; i < 3; i++){
    for (int j = 0; j < 3 - i ; j++){
      if (valores[j] > valores[j+1]){
        int temp = valores[j];
        valores[j] = valores[j+1];
        valores[j+1] = temp;
      }
    }
  }

  for (i=0; i < 3; i++){
    soma += valores[i];
  }
  printf("%d\n", soma);
  return 0;
}
