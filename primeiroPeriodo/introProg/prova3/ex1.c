#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(){

  int n, temp, i=0, j=0;

  scanf("%d", &n);
  int cod[n], pon[n];

  for(i=0; i<n; i++){
    scanf("%d", &cod[i]);
  } 
  for(i=0; i<n; i++){
    scanf("%d", &pon[i]);
  }

  if(n>=6 && n<=100){

    for(i=0; i<n-1; i++){
      for(j=0; j<n-1-i; j++){
        if(pon[j] < pon[j+1]){
          temp = pon[j];
          pon[j] = pon[j+1];
          pon[j+1] = temp;

          temp = cod[j];
          cod[j] = cod[j+1];
          cod[j+1] = temp;
        }
      }
    } 

    for(i=0; i<n-1; i++){
      for(j=0; j<n-1-i; j++){
        if(pon[j] == pon[j+1] && cod[j] > cod[j+1]){
          temp = pon[j];
          pon[j] = pon[j+1];
          pon[j+1] = temp;

          temp = cod[j];
          cod[j] = cod[j+1];
          cod[j+1] = temp;
        }
      }
    } 


    printf("%d\n", n);

    for(i=0; i<n; i++){
      printf("%d %d %d\n", i+1, cod[i], pon[i]);
    }

  }else{
    printf("CAMPEONATO INVALIDO!\n");
  }

  return 0;
}
