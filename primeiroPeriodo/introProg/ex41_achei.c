#include <stdio.h>

int main(){

  int n, i=0, m, temp, j=0, achei=0;

  scanf("%d", &n);
  int v[n];

  for(i=0; i<n; i++){
    scanf("%d", &v[i]);
  }

  scanf("%d", &m);

  for(i=0; i<m; i++){
    scanf("%d", &temp);

    for(j=0; j<n; j++){
      if(temp == v[j]){
        achei = 1;
        printf("ACHEI\n");
        break;
      }
    } 
    if(achei == 0){
      printf("NAO ACHEI\n");
    }
    achei = 0;
  } 

  return 0;
}
