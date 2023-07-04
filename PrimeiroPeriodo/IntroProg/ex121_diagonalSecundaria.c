#include <stdio.h>

int main(){

  int n, i=0, j=0;

  scanf("%d", &n);
  int mat[n][n];

  for(i=0; i<n; i++){
    for(j=0; j<n; j++){
      scanf("%d", &mat[i][j]);
    }
  }

  for(i=0; i<n; i++){
    for(j=n-1; j>=0; j--){
      printf("%d\n", mat[i][j]);
    }
  }


  return 0;
}
