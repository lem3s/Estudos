#include <stdio.h>

int main(){

  int casos, n;
  int contador=0, i=0, j=0;
  int contadorNulos=0, contadorUm=0, flag=0;
  int mat[50][50];

  scanf("%d", &casos);

  for(contador=0; contador<casos; contador++){
    scanf("%d", &n); 
    
    for(i=0; i<n; i++){
      for(j=0; j<n; j++){
        scanf("%d", &mat[i][j]); 
      }
    }

    //Verifica Linhas
    for(i=0; i<n; i++){
      if(flag == 0){
        for(j=0; j<n; j++){
          if(mat[i][j] == 0){
            contadorNulos++;
          }else if(mat[i][j] == 1){
            contadorUm++;
          }
        }
      }
      if(contadorNulos == n-1 && contadorUm == 1){ 
        flag = 0;
      }else{
        flag = 1; 
        break;
      }
      contadorUm = 0;
      contadorNulos = 0;
    }

    //Verifica Colunas
    if(flag == 0){
      for(i=0; i<n; i++){
        if(flag == 0){ 
          for(j=0; j<n; j++){
            if(mat[j][i] == 0){
              contadorNulos++;
            }else if(mat[j][i] == 1){
              contadorUm++;
            }
          }
        }
        if(contadorNulos == n-1 && contadorUm == 1){ 
          flag = 0;
        }else{
          flag = 1; 
          break;
        }
        contadorUm = 0;
        contadorNulos = 0;
      }
    }

    //Imprime o resultado
    if(flag == 1){
      printf("Nao permutacao\n");
    }else{
      printf("Matriz permutacao\n");
    }
  
    flag = 0;
    contadorUm = 0;
    contadorNulos = 0;
  }

  return 0;
}
