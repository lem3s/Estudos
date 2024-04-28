#include <stdio.h>

void bubbleSort(int arr[], int size);

int main(){
  int n, i=0;

  printf("Numbers of elements of the array: ");
  scanf("%d", &n);

  int arr[n]; 
  
  printf("Enter the elements to be sorted: ");
  for(i=0; i<n; i++){
    scanf("%d", &arr[i]);
  }

  bubbleSort(arr, n);

  printf("Sorted array: [");
  for(i=0; i<n; i++){
    if(i<n-1){
      printf("%d,", arr[i]);
    }else{
      printf("%d]\n", arr[i]);
    }
  }

  return 0;
}

void bubbleSort(int arr[], int size){
  int temp, i=0, j=0;
  for(i=0; i<size-1; i++){
    for(j=0; j<size-1-i; j++){
      if(arr[j] > arr[j+1]){
        temp = arr[j];
        arr[j] = arr[j+1];
        arr[j+1] = temp;
      }
    }
  }
}
