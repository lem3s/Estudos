#include <stdio.h>

void desenhaBorda();
void desenhaQuadrado();

int main(){

  int n, fundo, col, lin, i=0, j=0;

  scanf("%d %d", &n, &fundo);

  int mat[n][n];

  for(i=0; i<n; i++){
    for(j=0; j<n; j++){
      mat[i][j] = fundo;
    }
  }

  return 0;
}
