#include <stdio.h>
#include <string.h>

int main(){

  int m, n, i=0, j=0;
  char str[1000010];
  char sz[1000010];

  while(1){

    scanf("%d %d", &m, &n);

    if(m == 0 && n == 0){
      break;
    }
       
    sprintf(str, "%d", m+n);

    for(i=0; i<strlen(str); i++){
      if(str[i] != '0'){
        sz[j] = str[i];
        j++;
      }
    } 
    sz[j] = '\0';
      
    printf("%s\n", sz);
    sz[0] = '\0';
    j = 0;
  } 

  return 0;
}
