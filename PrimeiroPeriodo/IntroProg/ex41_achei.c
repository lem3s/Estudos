#include <stdio.h>

int main(){

  int n, i=0, m, temp, j=0;

  scanf("%d", &n);
  int v[n];

  for(i=0; i<n; i++){
    scanf("%d", &v[i]);
  }

  scanf("%d", &m);

  for(i=0; i<m; i++){
    scanf("%d\n", &temp);

    for(j=0; i<n; j++){
      if(temp == v[j]){
        printf("ACHEI\n");
        break;
      }
      if(j == n-1){
        printf("NAO ACHEI\n");
      }
    }
  }

  return 0;
}
