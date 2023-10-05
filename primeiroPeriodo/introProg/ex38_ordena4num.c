#include <stdio.h>

int main(){

  int i=0, j=0, temp;
  float arr[4];

  scanf("%f", &arr[0]);
  scanf("%f", &arr[1]);
  scanf("%f", &arr[2]);
  scanf("%f", &arr[3]);

  //Bubble Sort
  for (i = 0; i < 3; i++){
    for (j = 0; j < 3 - i; j++){
      if (arr[j] > arr[j+1]){
        temp = arr[j];
        arr[j] = arr[j+1];
        arr[j+1] = temp;
      }
    }
  }

  printf("%.2f, %.2f, %.2f, %.2f\n", arr[0], arr[1], arr[2], arr[3]);

  return 0;
}
