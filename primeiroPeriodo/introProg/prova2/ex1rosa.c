#include <stdio.h>

int main(){

  int n1, n2, n3, mmc=1, divisor=2, i=2, flag=0, verifica = 0, divisivel=0;

  scanf("%d %d %d", &n1, &n2, &n3);

  while (1){
    if(n1==1 && n2 == 1 && n3 == 1){
      break;
    }
    else if (n1%divisor == 0 || n2%divisor == 0 || n3%divisor == 0){
      printf("%d %d %d :%d\n", n1, n2, n3, divisor);
      if(n1%divisor == 0){
        n1 = n1/divisor;
      }
      if(n2%divisor == 0){
        n2 = n2/divisor;
      }
      if(n3%divisor == 0){
        n3 = n3/divisor;
      }
      mmc = mmc * divisor;
    }
    else{
      divisor++;
    }
  }
  printf("MMC: %d\n", mmc);


  return 0;
}
