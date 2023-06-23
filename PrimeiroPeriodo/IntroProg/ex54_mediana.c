#include <stdio.h>

int main(){

  int n, i=0, j=0, temp;
  double mediana;

  scanf("%d", &n);
  double arr[n];

  for(i=0; i<n; i++){
    scanf("%lf", &arr[i]);
  }

  for(i=0; i<n-1; i++){
    for(j=0; j<n-i-1; j++){
      if(arr[j] > arr[j+1]){
        temp = arr[j];
        arr[j] = arr[j+1];
        arr[j+1] = temp;
      } 
    }
  }

  if(n%2 == 0){
    mediana = (arr[n/2-1] + arr[n/2]) / 2;
  }else{
    mediana = arr[(n-1)/2];
  }

  printf("%.2lf\n", mediana);

  return 0;
}
