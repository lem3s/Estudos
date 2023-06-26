#include <stdio.h>
#include <string.h>

int main(){

  int m, n;
  char str[1000010];

  while(1){

    scanf("%d %d", &m, &n);

    if(m == 0 && n == 0){
      break;
    }

    sprintf(str, "%d", m+n);

    printf("%s\n", str);
    
  }




  return 0;
}
