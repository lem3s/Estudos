#include <stdio.h>

int main(){

  int n, b1, b2, soma=0, i=0, j=0;
  int cpf[11];

  scanf("%d", &n);

  for(i=0; i<n; i++){
    for(j=0; j<11; j++){
      scanf("%d", &cpf[j]);
      soma += cpf[j];
    }  

    b1 = (cpf[0]*1 + cpf[1]*2 + cpf[2]*3 + cpf[3]*4 + cpf[4]*5 + cpf[5]*6 + cpf[6]*7 + cpf[7]*8 + cpf[8]*9) % 11;
    if(b1 == 10){
      b1 = 0;
    }

    b2 = (cpf[0]*9 + cpf[1]*8 + cpf[2]*7 + cpf[3]*6 + cpf[4]*5 + cpf[5]*4 + cpf[6]*3 + cpf[7]*2 + cpf[8]*1) % 11;
    if(b2 == 10){
      b2 = 0;
    }

    if(soma%11==0 && b1 == cpf[9] && b2 == cpf[10]){
      printf("CPF valido\n");
    }else{
      printf("CPF invalido\n");
    }
    
    soma = 0;
  }

  return 0;
}
