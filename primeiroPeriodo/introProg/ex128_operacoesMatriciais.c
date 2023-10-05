#include <stdio.h>

int calculaTraco(int tamanho, int mat[][tamanho]);

int main(){

  int n, traco, i=0, j=0;

  scanf("%d", &n);
  
  int mat[n][n];
  int mult[n][n];
  int trans[n][n];

  for(i=0; i<n; i++){
    for(j=0; j<n; j++){
      scanf("%d", &mat[i][j]);
    } 
  }

  traco = calculaTraco(n, mat);

  //Mult[][] = traco * A
  for(i=0; i<n; i++){
    for(j=0; j<n; j++){
      mult[i][j] = mat[i][j] * traco;
    }
  }

  //Calcula transposta
  for(i=0; i<n; i++){
    for(j=0; j<n; j++){
      trans[i][j] = mat[j][i];
    }
  }

  //Calcula soma e imprime
  for(i=0; i<n; i++){
    for(j=0; j<n; j++){
      mult[i][j] += trans[i][j];
      printf("%d ", mult[i][j]);
    }
    printf("\n");
  }

  return 0;
}

int calculaTraco(int tamanho, int mat[][tamanho]){
  int i=0, j=0, soma=0;

  for(i=0; i<tamanho; i++){
    soma += mat[i][j];
    j++;
  }

  return soma;
}
