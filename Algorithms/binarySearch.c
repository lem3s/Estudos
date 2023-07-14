#include <stdio.h>

int binarySearch();

int main(){
  int n, i=0;
   
  printf("Numbers of elements of the array: ");
  scanf("%d", &n);

  int arr[n]; 
  
  printf("Enter the elements: ");
  for(i=0; i<n; i++){
    scanf("%d", &arr[i]);
  }


  return 0;
}
