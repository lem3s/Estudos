#include <stdio.h>

int main(){

  int i=0, j=0;
  double mat[2][2];

  for(i=0; i<2; i++){
    for(j=0; j<2; j++){
      scanf("%lf", &mat[i][j]);
    }
  }

  printf("%.3lf ", mat[0][0] * mat[0][0] + mat[0][1] * mat[1][0]);
  printf("%.3lf\n", mat[0][0] * mat[0][1] + mat[0][1] * mat[1][1]);
  printf("%.3lf ", mat[1][0] * mat[0][0] + mat[1][1] * mat[1][0]);
  printf("%.3lf\n", mat[1][0] * mat[0][1] + mat[1][1] * mat[1][1]);

  //desculpa, eu sei q esse código ficou horível, vou tentar melhorar

  return 0;
}
