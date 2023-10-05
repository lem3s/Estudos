#include <stdio.h>

int main(){

  int l, c, largura, valor, i=0, j=0;

  scanf("%d", &l);
  scanf("%d", &c);
  scanf("%d", &largura);
  scanf("%d", &valor);

  int mat[l][c];

  for(i=0; i<l; i++){
    for(j=0; j<c; j++){
      mat[i][j] = 0;
    }
  }

  for(i=0; i<largura; i++){
    for(j=0; j<c; j++){
      mat[i][j] = valor;
    }
  }

  for(i=l-largura; i<l; i++){
    for(j=0; j<c; j++){
      mat[i][j] = valor;
    }
  }

  for(i=0; i<l; i++){
    for(j=0; j<largura; j++){
      mat[i][j] = valor;
    }
  }

  for(i=0; i<l; i++){
    for(j=c-largura; j<c; j++){
      mat[i][j] = valor;
    }
  }

  printf("P2\n");
  printf("%d %d\n", c, l);
  printf("255\n");

  for(i=0; i<l; i++){
    for(j=0; j<c; j++){
      printf("%d ", mat[i][j]);
    }
    printf("\n");
  }

  return 0;
}
