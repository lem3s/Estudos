#include <stdio.h>

int main(void){
  int ano, passagem = 1986, i=0;

  scanf("%d", &ano);

  if (ano >= 1986){
    while (passagem <= ano){
      passagem += 76;
    }
  }
  else if (ano < 1986){
    while (passagem > ano){
      i++;
      passagem -= 76;
      if (i == 21){
        passagem--;
      }
    }
    passagem += 76;
  }

  printf("%d\n", passagem);
}
