#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
  char ini[7], fin[7];
  char str[9];
  int n, i=0, j=0, k=0;

  scanf("%d", &n);

  for(i=0; i<n; i++){
    scanf("%s %s", ini, fin);

    for(j=0; j<=atoi(fin)-atoi(ini); j++){
      printf("%d", atoi(ini)+j);
    }

    for(j=0; j<=atoi(fin)-atoi(ini); j++){
      sprintf(str, "%d", atoi(fin)-j);

      for(k=strlen(str); k>=0; k--){
        printf("%c", str[k]);
      }
    }

    printf("\n");
  }

  return 0;
}
