#include <stdio.h>

int main(void){

  int n, m, g, h, i, j, k, l;

  scanf("%d %d", &m, &n);

  int mat1[m][n], mat2[m][n];

  for (i=0; i < m; i++){
    for (j=0; j < n; j++){
      scanf("%d", &mat1[i][j]);
    }
  }

  char op;
  getchar();
  scanf("%c", &op);

  for (i=0; i < m; i++){
    for (j=0; j < n; j++){
      scanf("%d", &mat2[i][j]);
    }
  }

  if (op == '+'){
    for (i=0; i < m; i++){
      for (j=0; j < n; j++){
        printf("%d", mat1[i][j] + mat2[i][j]);
        if (j != n - 1){
          printf(" ");
        }
      }
      printf("\n");
    }
  }
  else if (op == 'x' && m == n){
    int soma;
    int res[m][n];

    for (i=0; i < m; i++){
      for (j=0; j < n; j++){
        for (k=0; k < n; k++){
          soma += mat1[i][k] * mat2[k][j];
        }
        res[i][j] = soma; 
        printf("%d", res[i][j]);
        if (j != n - 1){
          printf(" ");
        }
        soma = 0;
      }
      printf("\n");
    }
  }
  else {
    printf("ERROR\n");
  }

  return 0;
}
