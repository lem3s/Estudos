#include <stdio.h>
#include <math.h>

int main(){

  int n, i=0, j=0;
  float coordx, coordy, coordz; 

  scanf("%d", &n);
  float arr[n*3];
  float coord[3];

  for(i=0; i<n*3; i+=3){
    scanf("%f %f %f", &arr[i], &arr[i+1], &arr[i+2]);
  }

  for(i=0; i<n-1; i++){
    coordx = fabs(arr[j+3] - arr[j]);
    coordy = fabs(arr[j+4] - arr[j+1]);
    coordz = fabs(arr[j+5] - arr[j+2]);

    if(coordx > coordy && coordx > coordz){
      printf("%.2f\n", coordx);
    }
    else if(coordy > coordx && coordy > coordz){
      printf("%.2f\n", coordy);
    }
    else if(coordz > coordx && coordz > coordy){
      printf("%.2f\n", coordz);
    }
    else{
      printf("%.2f\n", coordy);
    }

    j+=3;
  }


  return 0;
}
