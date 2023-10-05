#include <stdio.h>
#include <stdlib.h>

int main(void){
  char n1[3], n2[3];
  char aux;

  scanf("%s", n1);
  scanf("%s", n2);

  int i=0;

  aux = n1[0];
  n1[0] = n1[2];
  n1[2] = aux;
  printf("n1: %s\n", n1);

  aux = n2[0];
  n2[0] = n2[2];
  n2[2] = aux;
  printf("n2: %s\n", n2);

  if (atoi(n1) > atoi(n2)){
    printf("%d\n", atoi(n1));
  }
  else if (atoi(n2) > atoi(n1)){
    printf("%d\n", atoi(n2));
  }
}
