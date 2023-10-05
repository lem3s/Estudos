#include <stdio.h>
#include <string.h>

#define MAX 10000

int  main(){

  int n, soma=0, i=0, j=0;
  char num[MAX];

  scanf("%d", &n);

  for(i=0; i<n; i++){
    scanf("%s", num);

    for(j=0; j<strlen(num); j++){
      switch(num[j]){
        case('0'):
          soma+=6;
          break;
        case('1'):
          soma+=2;
          break;
        case('2'):
          soma+=5;
          break;
        case('3'):
          soma+=5;
          break;
        case('4'):
          soma+=4;
          break;
        case('5'):
          soma+=5;
          break;
        case('6'):
          soma+=6;
          break;
        case('7'):
          soma+=3;
          break;
        case('8'):
          soma+=7;
          break;
        case('9'):
          soma+=6;
          break;
      }
    } 

    printf("%d leds\n", soma);
    soma = 0;
  }

  return 0;
}

