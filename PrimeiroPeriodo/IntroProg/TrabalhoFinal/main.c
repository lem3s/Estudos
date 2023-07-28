#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_HOSPEDE 100
#define ANDARES 4
#define QUARTOS_ANDAR 20  //Apenas numeros pares

// Definição da estrutura hospede
struct Hospede {
    char nome[50];
    char email[100];
    char telefone[15];
};

void bubbleSort(int arr[], int n){
  int aux;
  for(int i=0; i<n-1; i++){
    for(int j=0; j<n-1-i; j++){
      if(arr[j] > arr[j+1]){
        aux = arr[j];
        arr[j] = arr[j+1];
        arr[j+1] = aux;
      }
    }
  }
}

// Função para cadastrar um novo hospede na agenda estática
int cadastrarHospede(struct Hospede hospede[], int numHospedes) {
    if (numHospedes >= MAX_HOSPEDE) {
        printf("O hotel está cheio. Não é possível cadastrar mais hospedes.\n");
        return numHospedes;
    }

    struct Hospede novoHospede;

    printf("Digite o nome do hospede: ");
    scanf(" %[^\n]", novoHospede.nome);

    printf("Digite o email do hospede: ");
    scanf(" %[^\n]", novoHospede.email);

    printf("Digite o telefone do hospede: ");
    scanf(" %[^\n]", novoHospede.telefone);

    hospede[numHospedes] = novoHospede;

    printf("Hospede cadastrado com sucesso!\n");

    return numHospedes + 1;
}

// Função para exibir todos os hospedes cadastrados
void exibirHospedes(struct Hospede hospedes[], int numHospedes) {
    if (numHospedes == 0) {
        printf("Nenhum hospede cadastrado no hotel.\n");
        return;
    }

    printf("Hospedes cadastrados na agenda:\n");
    for (int i = 0; i < numHospedes; i++) {
        printf("Cliente %d:\n", i + 1);
        printf("Nome: %s\n", hospedes[i].nome);
        printf("Email: %s\n", hospedes[i].email);
        printf("Telefone: %s\n", hospedes[i].telefone);
        printf("\n");
    }
}

void exibirStatus(){
  int numQuarto=1;
  /*
  printf("┌");
  printf("┐");
  printf("└");
  printf("┘");
  printf("─");
  printf("│");
  */

  system("clear");

  for(int i=0; i<ANDARES; i++){
    printf("%d° andar: \n", i+1);

    for(int h=0; h<2; h++){
      if(h==0){
        numQuarto = 1;
      }
      for(int j=0; j<QUARTOS_ANDAR/2; j++){
        printf("┌");
        printf("─");
        printf("─");
        printf("─");
        printf("┐"); 
      }
      printf("\n");

      for(int j=0; j<QUARTOS_ANDAR/2; j++){
        printf("│");
        if(h==0){
          printf("%d", (i+1)*100+numQuarto);
          numQuarto+=2;
        }
        else if (h==1){
          printf("%d", (i+1)*100+numQuarto);
          numQuarto+=2;
        }


        printf("│");
      }
      printf("\n");

      for(int j=0; j<QUARTOS_ANDAR/2; j++){
        printf("└");
        printf("─");
        printf("─");
        printf("─");
        printf("┘");
      }
      printf("\n");
      numQuarto = 2;
    }
  }

  char espera;
  getchar();
  scanf("%c", &espera);
}

int main() {
    struct Hospede agenda[MAX_HOSPEDE];
    int numHospedes = 0;
    char opcao;

    do {
        printf("MENU:\n");
        printf("1 - Cadastrar novo hospede\n");
        printf("2 - Exibir hospedes cadastrados\n");
        printf("3 - Exibir status quartos\n");
        printf("0 - Sair\n");
        printf("Escolha uma opção: ");
        scanf(" %c", &opcao);

        switch (opcao) {
            case '1':
                numHospedes = cadastrarHospede(agenda, numHospedes);
                break;
            case '2':
                exibirHospedes(agenda, numHospedes);
                break;
            case '3':
                exibirStatus();
                break;
            case '0':
                printf("Saindo...\n");
                break;
            default:
                printf("Opção inválida! Tente novamente.\n");
        }

        printf("\n");
    } while (opcao != '0');

    return 0;
}

