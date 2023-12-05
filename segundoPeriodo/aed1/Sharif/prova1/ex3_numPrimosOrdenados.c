#include <stdio.h>

// Calcula os n primeiros números primos
void numPrimos(long int arr[], int n); 

// Ordena um array em ordem crescente utilizando Bubble Sort
void bubbleCres(int arr[], int n);

int main(void){

  int n, i, j, k;

  scanf("%d", &n);

  int arr[n];

  // Lê os valores dados pelo usuário
  for (i = 0; i < n; i++){
    scanf("%d", &arr[i]);
  }

  // Calcula e armazena em um array os valores correspondentes
  // aos numeros primos da ordem dada pelo usuário
  int maior = -1;
  for (i = 0; i < n; i++){
    if (arr[i] > maior){
      maior = arr[i];
    }
  }

  long primos[maior];
  numPrimos(primos, maior);

  // Ordena o array de numeros primos
  bubbleCres(arr, n);

  // Imprime e calcula a soma dos números primos desejados
  int soma = 0;
  for (i = 0; i < n; i++){
    printf("%ld ", primos[arr[i] - 1]);
    soma += primos[arr[i] - 1];
  }
  printf("\n%d", soma);

  return 0;
}

// Retorna o número primo correspondente à ordem x
void numPrimos(long int arr[], int n){
  long int res = 2;
  int i, j, flag = 0;

  // Para cada ordem de 0 a x - 1
  for (i = 0; i < n; i++){

    while (1){
      flag = 0;

      // Verifica se o número é divisível por algum número entre 2 e ele mesmo
      for (j = 2; j <= res / 2; j++){
        if (res % j == 0){
          // O número é divisível por algum número além de 1 e ele mesmo
          // Então o número não é primo
          flag = 1;
          break;
        }
      }

      if (flag == 0){
        res ++;
        arr[i] = res - 1;
        break;
      }

      res++;
    }
  }
}

void bubbleCres(int arr[], int n){
  int i, j;
  int aux;

  for (i = 0; i < n - 1; i++){
    for (j = 0; j < n - 1 - i; j++){
      if (arr[j] > arr[j + 1]){
        aux = arr[j];
        arr[j] = arr[j + 1];
        arr[j + 1] = aux;
      }
    }
  }
}
