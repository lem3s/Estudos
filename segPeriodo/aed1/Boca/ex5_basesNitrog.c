#include <stdio.h>

int main(void){

  int n, i, j, k;
  char str[200];

  int quoc, resto; 

  scanf("%d", &n);
  int arr[n];

  for (i=0; i < n; i++){
    scanf("%d", &arr[i]);
  }

  for (i=0; i < n; i++){
    quoc = arr[i];
    j = 0;

    do{
      resto = quoc % 4;
      quoc = quoc / 4;

      switch (resto){
        case(0):
          str[j] = 'A';
          break;
        case(1):
          str[j] = 'C';
          break;
        case(2):
          str[j] = 'G';
          break;
        case(3):
          str[j] = 'T';
          break;
      }
      j++;

    }while (quoc > 0);

    for (j--; j >= 0; j--){
      printf("%c", str[j]); 
    }
    printf("\n");
  }

  return 0;
}
