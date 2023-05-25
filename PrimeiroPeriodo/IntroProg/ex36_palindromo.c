#include <stdio.h>

int main(){
  int num, n1, n2, n3, n4, n5;

  scanf ("%d", &num);
  
  // >6 Dígitos
  if (num >= 100000){
    printf("NUMERO INVALIDO\n");

  //5 Dígitos
  }else if (num < 100000 && num >= 10000){
    n1 = num / 10000;
    n2 = (num % 10000) / 1000;
    n3 = (num % 1000) / 100;
    n4 = (num % 100) / 10;
    n5 = num % 10;

    if (n1 == n5 && n2 == n4){
      printf("PALINDROMO\n");
    }else{
      printf("NAO PALINDROMO\n");
    }

  //4 Dígitos
  } else if (num < 10000 && num >= 1000){
    n1 = num / 1000;
    n2 = (num % 1000) / 100;
    n3 = (num % 100) / 10;
    n4 = num % 10;

    if (n1 == n4 && n2 == n3){
      printf("PALINDROMO\n");
    }else{
      printf("NAO PALINDROMO\n");
    }
  }

  //3 Dígitos
  else if(num < 1000 && num >= 100){
    n1 = num / 100;
    n2 = (num % 100) / 10;
    n3 = num % 10;

    if (n1 == n3){
      printf("PALINDROMO\n");
    } else{
      printf("NAO PALINDROMO\n");
    }
  }
  

  //2 Dígitos
  else if(num < 100 && num >= 10){
    n1 = num / 10;
    n2 = num % 10;

    if (n1 == n2){
      printf("PALINDROMO\n");
    }else{
      printf("NAO PALINDROMO\n");
    }
  }

  // < 1 Dígito
  else{
    printf("NUMERO INVALIDO\n");
  }
    
  return 0;
}
