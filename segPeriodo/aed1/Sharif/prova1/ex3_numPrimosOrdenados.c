#include <stdio.h>

// Retorna o número primo correspondente à ordem x
long int numPrimo(int x);

// Ordena um array em ordem crescente utilizando Bubble Sort
void bubbleCres(long int arr[], int n);

int main(void){

  int n, i;

  scanf("%d", &n);

  int arr[n];

  // Lê os valores dados pelo usuário
  for (i = 0; i < n; i++){
    scanf("%d", &arr[i]);
  }

  // Calcula e armazena em um array os valores correspondentes
  // aos numeros primos da ordem dada pelo usuário
  long int primos[n];
  for (i = 0; i < n; i++){
    primos[i] = numPrimo(arr[i]);
  }

  // Ordena o array de numeros primos
  bubbleCres(primos, n);

  // Imprime e calcula a soma dos números primos desejados
  int soma = 0;
  for (i = 0; i < n; i++){
    printf("%ld ", primos[i]);
    soma += primos[i];
  }
  printf("\n%d\n", soma);

  return 0;
}

// Retorna o número primo correspondente à ordem x
long int numPrimo(int x){
  int res = 2, flag = 0;
  int i, j;

  // Para cada ordem de 0 a x - 1
  for (i = 0; i < x; i++){

    while (1){
      flag = 0;

      // Verifica se o número é divisível por algum número entre 2 e ele mesmo
      for (j = 2; j < res; j++){
        if (res % j == 0){
          // O número é divisível por algum número além de 1 e ele mesmo
          // Então o número não é primo
          flag = 1;
          break;
        }
      }

      if (flag == 0){
        res ++;
        break;
      }

      res++;
    }
  }

  return res - 1;
}

void bubbleCres(long int arr[], int n){
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
