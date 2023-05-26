#include <stdio.h>

int main(){
  
  int n, i;

  scanf("%d", &n);

  double tempF[n];
  double tempC[n];

  i = 0;
  for(i=0; i < n; i++){
    scanf("%lf", &tempF[i]);
  } 

  i=0;
  for(i=0; i < n; i++){
    tempC[i] = 5*(tempF[i] - 32)/9;
  }

  i=0;
  for(i=0; i < n; i++){
    printf("%.2lf FAHRENHEIT EQUIVALE A %.2lf CELSIUS\n", tempF[i], tempC[i]);
  }


  return 0;
}
