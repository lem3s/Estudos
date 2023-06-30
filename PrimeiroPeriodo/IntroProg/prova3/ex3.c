#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(){

  int n, soma1ametade=0, soma2ametade=0, i=0;
  float media, somatot=0;

  scanf("%d", &n);
  int arr[n];
  for(i=0; i<n; i++){
    scanf("%d", &arr[i]);
    somatot += arr[i];
  }

  if(n>5){
    media = somatot/n;

    if(n%2 == 0){
      for(i=0; i<(n/2)-1; i++){
        if(arr[i] > media){
          soma1ametade++;
        }
      }
      for(i=n/2; i<n; i++){
        if(arr[i] > media){
          soma2ametade++;
        }
      }

    }else if(n%2 != 0){
      for(i=0; i<(n-1)/2; i++){
        if(arr[i] > media){
          soma1ametade++;
        }
      }
      for(i=(n+1)/2; i<n; i++){
        if(arr[i] > media){
          soma2ametade++;
        }
      }
    }

    if(soma1ametade > soma2ametade){
      printf("%.2f %d %d PRIMEIRA METADE\n", media, soma1ametade, soma2ametade);
    }else if(soma1ametade < soma2ametade){
      printf("%.2f %d %d SEGUNDA METADE\n", media, soma1ametade, soma2ametade);
    }else {
      printf("%.2f %d %d EMPATE\n", media, soma1ametade, soma2ametade);
    }

  }else{
    printf("QUANTIDADE DE ELEMENTOS INVALIDOS!\n");
  }


  return 0;
}
