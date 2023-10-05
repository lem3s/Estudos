#include <stdio.h>

int main(){
  int n1, n2, n3;
  int a, b, c;

  scanf("%d %d %d", &n1, &n2, &n3);

  if ((n1 > n2) && (n1 > n3)){
    a = n1;
    b = n2;
    c = n3;
  }else if ((n2 > n1) && (n2 > n3)){
    a = n2;
    b = n1;
    c = n3;
  }else if ((n3 > n1) && (n3 > n2)){
    a = n3;
    b = n1;
    c = n3;
  }else{
    a = n1;
    b = n2;
    c = n3;
  }

  if ((a*a) < ((b*b) + (c*c))){
    printf("acutangulo\n");
  }else if ((a*a) == ((b*b) + (c*c))){
    printf("retangulo\n");
  }else if((a*a) > ((b*b) + (c*c))){
    printf("obtusangulo\n");
  }

  return 0;
}
