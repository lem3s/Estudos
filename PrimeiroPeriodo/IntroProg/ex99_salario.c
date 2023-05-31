#include <stdio.h>

int main(){

  int mat;
  double sal, h;

  while(1){
    scanf("%d %lf %lf", &mat, &h, &sal);
    if(mat == 0){
      break;
    }
    printf("%d %.2lf\n", mat, h*sal);
  }
  
  return 0;
}
