#include <stdio.h>
#include <math.h>

void dist(float ax, float ay, float az, float bx, float by, float bz){
  float res;

  res = sqrt(pow(ax-bx, 2) + pow(ay-by, 2) + pow(az-bz, 2));
  printf("%.2f\n", res);
}


int main(){

  int n, i=0, j=0;

  scanf("%d", &n);
  float arr[n*3];

  for(i=0; i<n*3; i+=3){
    scanf("%f %f %f", &arr[i], &arr[i+1], &arr[i+2]);
  }

  for(i=0; i<n-1; i++){
    dist(arr[j], arr[j+1], arr[j+2], arr[j+3], arr[j+4], arr[j+5]);
    j+= 3;
  } 




  return 0;
}

