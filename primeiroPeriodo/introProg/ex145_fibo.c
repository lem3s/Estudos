#include <stdio.h>

int fibo(int t1, int t2, int n); 

int main(){
  
  int t1, t2, n;

  scanf("%d %d %d", &t1, &t2, &n);

  printf("%d\n", fibo(t1, t2, n));

  return 0;
}

int fibo(int t1, int t2, int n){
  int i=0;
  int aux;

  for(i=0; i<n-2; i++){
    aux = t2;
    t2 += t1;
    t1 = aux;
  }

  return t2;
}
