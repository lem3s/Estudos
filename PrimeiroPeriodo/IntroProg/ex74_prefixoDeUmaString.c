#include <stdio.h>

int main(){

  int n, i=0, j=0;

  scanf("%d", &n);
  getchar();
  char str[510];

  for(i=0; i<n; i++){
    fgets(str, 510, stdin);

    for(j=0; j<str[0]; j++){
      printf("%c", str[j+2]);
    }
    printf("\n");
  }

  return 0;
}
