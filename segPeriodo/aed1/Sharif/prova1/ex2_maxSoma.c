#include <stdio.h>

int main(void){

  int t, i, j, k;

  scanf("%d", &t);

  int mat[t][10000];
  int ns[t];

  // Armazenar os valores
  for (i = 0; i < t; i++){
    scanf("%d", &ns[i]);

    for (j = 0; j < ns[i]; j++){
      scanf("%d", &mat[i][j]);
    }
  }

  int soma = -1, pares = 0;
  for (i = 0; i < t; i++){

    // Procura qual a maior soma possível
    for (j = 0; j < ns[i]; j++){
      for (k = 0; k < ns[i]; k++){
        if (j != k && (mat[i][j] + mat[i][k]) > soma){
          soma =  mat[i][j] + mat[i][k];
        }
      }
    }

    // Procura quantas combinações dão a maior soma
    for (j = 0; j < ns[i]; j++){
      for (k = 0; k < ns[i]; k++){
        if (j != k && (mat[i][j] + mat[i][k]) == soma){
          pares++;
        }
      }
    }

    // Imprime o resultado dividindo por 2, já que as 
    // combinações são contadas duplicadas
    printf("%d\n", pares / 2);

    soma = -1;
    pares = 0;
  }

  return 0;
}
