#include <stdio.h>

double calculaDeterminante(double a, double b, double c, double d);

int main(){

  double mat[2][2];

  scanf("%lf %lf %lf %lf", &mat[0][0], &mat[0][1], &mat[1][0], &mat[1][1]);

  printf("%.2lf\n", calculaDeterminante(mat[0][0], mat[0][1], mat[1][0], mat[1][1]));
}

double calculaDeterminante(double a, double b, double c, double d){
  return a*d - c*b;
}
