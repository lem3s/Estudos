#include <stdio.h>

int main(){

  int matricula, pres, i=0;
  float p1, p2, p3, p4, p5, p6, p7, p8, l1, l2, l3, l4, l5, tf;
  float arr[10000];

  while (1){
    scanf("%d %f %f %f %f %f %f %f %f %f %f %f %f %f %f %d", &matricula, &p1, &p2, &p3, &p4, &p5, &p6, &p7, &p8, &l1, &l2, &l3, &l4, &l5, &tf, &pres);
    if (matricula != -1){
      arr[i] = matricula; 
      i++;
      arr[i] = 0.7 * ((p1+p2+p3+p4+p5+p6+p7+p8)/8) + 0.15 * ((l1+l2+l3+l4+l5)/5) + 0.15 * tf;
      i++;
      arr[i] = pres;
      i++;
    }
    else{
      break;
    }
  }

  int n = i+1;
  printf("n:%d i:%d\n", n, i);
  i = 0;
  for(i=0; i < n; i++){
    printf("Matricula: %.0f, ", arr[i]);
    printf("Nota Final: %.2f, Situacao Final: ", arr[i+1]);

    if (arr[i] > 6 && arr[i+2] > 96){
      printf("APROVADO\n");
    }
    else if(arr[i] > 6 && arr[i+2] < 96){
      printf("REPROVADO POR FREQUENCIA\n");
    }
    else if(arr[i] < 6 && arr[i+2] < 96){
      printf("REPROVADO POR NOTA\n");
    }
    else if(arr[i] < 6 && arr[i+2] < 96){
      printf("REPROVADO POR NOTA E POR FREQUENCIA\n");
    }
  }

  return 0;
}
