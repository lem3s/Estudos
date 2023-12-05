#include <stdio.h>
#include <stdlib.h>

int main(void){
  char n1[4], n2[4];

  scanf("%c%c%c %c%c%c", &n1[2], &n1[1], &n1[0], &n2[2], &n2[1], &n2[0]);
  n1[3] = '\0';
  n2[3] = '\0';

  if (atoi(n1) > atoi(n2)){
    printf("%d\n", atoi(n1));
  }
  else {
    printf("%d\n", atoi(n2));
  }

  return 0;
}
