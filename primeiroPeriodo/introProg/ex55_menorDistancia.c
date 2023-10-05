#include <stdio.h>
#include <math.h>

int main(){

  int t, n, i=0, j=0, k=0, cont=0;
  int temp_dist=10001, dist=10001;

  scanf("%d", &t);
  int arr[1010];

  for(i=0; i<t; i++){
    scanf("%d", &n);

    for(j=0; j<n; j++){
      scanf("%d", &arr[j]);
    }

    for(j=0; j<n; j++){
      for(k=0; k<n; k++){
        if(fabs(arr[j]-arr[k]) != 0){
          temp_dist = fabs(arr[j]-arr[k]);
          if(temp_dist < dist){
            dist = temp_dist;
          }
        }
        cont++;
      }
    }

    if(temp_dist == 10001){
      dist = 0;
    }

    printf("%d %d\n", dist, cont);
    cont = 0;
    temp_dist = 10001;
    dist = 10001;
  }


  return 0;
}
