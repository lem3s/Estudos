#include <stdio.h>

int main(){

  int tipo, i, j;
  float arr[3], temp;

 scanf("%d", &tipo);

 i = 0;
 for (i = 0; i < 3; i++){
   scanf("%f", &arr[i]);
  }

 if (tipo == 1){
   i = 0;
   j = 0;
   for (i = 0; i < 2; i++){
     for (j = 0; j < 2 - i; j++){
       if (arr[j] > arr[j+1]){
         temp = arr[j];
         arr[j] = arr[j+1];
         arr[j+1] = temp;
       }
     }
   }
 }

 else if (tipo == 2){
   i = 0;
   j = 0;
   for (i = 0; i < 2; i++){
     for (j = 0; j < 2 - i; j++){
       if (arr[j] < arr[j+1]){
         temp = arr[j];
         arr[j] = arr[j+1];
         arr[j+1] = temp;
       }
     }
   }
 }

 else if (tipo == 3){
   i = 0;
   j = 0;
   for (i = 0; i < 2; i++){
     for (j = 0; j < 2 - i; j++){
       if (arr[j] > arr[j+1]){
         temp = arr[j];
         arr[j] = arr[j+1];
         arr[j+1] = temp;
       }
     }
   }
   temp = arr[1];
   arr[1] = arr[2];
   arr[2] = temp;

   temp = arr[0];
   arr[0] = arr[2];
   arr[2] = temp;    
 }

  printf("%.2f %.2f %.2f\n", arr[0], arr[1], arr[2]);



  return 0;
}
