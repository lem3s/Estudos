#include <stdio.h>

int binarySearch(int arr[], int size, int item);

int main(){
  int n, item, i=0;
   
  printf("Numbers of elements of the array: ");
  scanf("%d", &n);

  int arr[n]; 
  
  printf("Enter the elements: ");
  for(i=0; i<n; i++){
    scanf("%d", &arr[i]);
  }

  printf("Enter the element you want to search: ");
  scanf("%d", &item);
  
  printf("Index: %d\n", binarySearch(arr, n, item));

  return 0;
}

int binarySearch(int arr[], int size, int item){
  int low = 0;
  int high = size-1;
  int mid, guess;

  while (low <= high){
    mid = (low+high)/2;
    guess = arr[mid];
    if (guess == item){
      return mid;
    }
    if(guess > item){
      high = mid - 1;
    }else{
      low = mid + 1;
    }
  }
  return -1;
}
