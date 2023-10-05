#include <stdio.h>
#include <string.h>

int main(){

  int n, i=0;
  char str[10];

  scanf("%d", &n);
  getchar();

  for(i=0; i<n; i++){
    fgets(str, 10, stdin);

    if(strlen(str) > 5){
      printf("3\n");
    }else{
      if((str[1] == 'n' && str[2] == 'e') || (str[0] == 'o' && str[2] == 'e') || (str[0] == 'o' && str[1] == 'n')){
        printf("1\n");
      }else if((str[1] == 'w' && str[2] == 'o') || (str[0] == 't' && str[2] == 'o') || (str[0] == 't' && str[1] == 'w')){
        printf("2\n");
      }
    }
  }

  return 0;
}
