#include <stdio.h>

int main(){

  double renda, pcapta, pessoas, sal_min=937.0;
  long int escola, etnia;
  int totl1=0, totl2=0, totl3=0, totl4=0, totn=0;
  

  while(renda != -1){
    scanf("%lf %lf %ld %ld", &renda, &pessoas, &escola, &etnia);
    pcapta = renda/pessoas;

    //Cota L1
    if (escola == 2 && pcapta <= 1.5*sal_min && etnia == 4){
      printf("ALUNO COTISTA (L1)\n");
      totl1 ++;
    }
    //Cota L2
    else if(escola == 2 && pcapta <= 1.5*sal_min && etnia != 4){
      printf("ALUNO COTISTA (L2)\n");
      totl2 ++;
    }
    //Cota L3
    else if(escola == 2 && etnia == 4){
      printf("ALUNO COTISTA (L3)\n");
      totl3++;
    }
    //Cota L4
    else if(escola == 2 && etnia != 4){
      printf("ALUNO COTISTA (L4)\n");
      totl4++;
    }
    //Nao COTISTA
    else if(escola == 1){
      printf("ALUNO NAO COTISTA\n");
      totn++;
    }
  }

  printf("TOTAL (L1): %d\n", totl1);
  printf("TOTAL (L2): %d\n", totl2);
  printf("TOTAL (L3): %d\n", totl3);
  printf("TOTAL (L4): %d\n", totl4);
  printf("TOTAL NAO COTISTA: %d\n", totn);
  
  return 0;
}
