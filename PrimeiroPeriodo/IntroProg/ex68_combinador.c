#include <stdio.h>
#include <string.h>

int main(){

  int n, i=0, j=0, len;
  char str1[50], str2[50];

  scanf("%d", &n);

  for(i=0; i<n; i++){
    scanf("%s", str1);
    scanf("%s", str2);

    if(strlen(str1) > strlen(str2)){
      len = strlen(str1);
    }else{
      len = strlen(str2);
    }

    for(j=0; j<len; j++){
      printf("%c", str1[j]);
      printf("%c", str2[j]);
    }
    printf("\n");
  }

  return 0;
}
