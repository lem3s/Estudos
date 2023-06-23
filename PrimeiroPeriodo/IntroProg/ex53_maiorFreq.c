#include <stdio.h>

int main(){

  int n, i=0, j=0, temp;

  scanf("%d",&n);
  int arr[n];

  for(i=0; i<n; i++){
    scanf("%d", &arr[i]);
  }

  for(i=0; i<n-1; i++){
    for(j=0; j<n-1-i; j++){
      if(arr[j] > arr[j+1]){
        temp = arr[j];
        arr[j] = arr[j+1];
        arr[j+1] = temp;
      }
    }
  }

  int num = arr[0];
  int freq = 1;
  int num_temp, freq_temp;

  for(i=0; i<n; i++){
    if(arr[i] == arr[i+1]){
      num_temp = arr[i];
      freq_temp ++;
      if(freq_temp > freq){
        freq = freq_temp;
        num = num_temp;
      } 
    }
    else{
      freq_temp = 1;
    }
  }

  printf("%d\n", num);
  printf("%d\n", freq);

  return 0;
}
