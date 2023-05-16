#include <stdio.h>

int main(){
  float a, b, c;

  scanf("%f", &a);
  scanf("%f", &b);
  scanf("%f", &c);

  if ((a < b) && (a < c)){
    if (b < c){
      printf("%.2f, %.2f, %.2f\n", a, b, c);
    }
    if (c < b){
      printf("%.2f, %.2f, %.2f\n", a, c, b);
    }
  }

  if ((b < a) && (b < c)){
    if (a < c){
      printf("%.2f, %.2f, %.2f\n", b, a, c);
    }
    if (c < a){
      printf("%.2f, %.2f, %.2f\n", b, c, a);
    }
  }

  if ((c < a) && (c < b)){
    if (a < b){
      printf("%.2f, %.2f, %.2f\n", c, a, b);
    }
    if (b < a){
      printf("%.2f, %.2f, %.2f\n", c, b, a);
    }
  }

  return 0;
}
