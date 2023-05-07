#include <stdio.h>

int main(){
  char num[3] = "";
  char inv[3] = "000";

  scanf("%s", num);

  inv[0] = num[2];
  inv[1] = num[1];
  inv[2] = num[0];

  printf("%s\n", inv);

  return 0;
}
