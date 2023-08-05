#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define MAX_HOSPEDE 100
#define ANDARES 4
#define QUARTOS_ANDAR 20  //Apenas numeros pares

// Definição da estrutura hospede
struct Hospede {
    char nome[50];
    char email[100];
    char telefone[15];
    char quarto[8];
    char entrada[10];
    char saida[10];
};

//Funções para retornar os dados tempo
int getDia(){
  time_t t = time(NULL);
  struct tm tm = *localtime(&t);

  return tm.tm_mday;
}

int getMes(){
  time_t t = time(NULL);
  struct tm tm = *localtime(&t);

  return tm.tm_mon+1;
}

int getAno(){
  time_t t = time(NULL);
  struct tm tm = *localtime(&t);

  return tm.tm_year+1900;
}

int getHoras(){
  time_t t = time(NULL);
  struct tm tm = *localtime(&t);

  return tm.tm_hour;
}

int converteQuarto(struct Hospede hospedes[], int i){
  char auxStr1[4];

  auxStr1[0] = hospedes[i].quarto[0];
  auxStr1[1] = hospedes[i].quarto[1];
  auxStr1[2] = hospedes[i].quarto[2];
  auxStr1[3] = '\0';

  return atoi(auxStr1);
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

    printf("Digite o quarto do hospede: ");
    scanf(" %[^\n]", novoHospede.quarto);

    printf("Digite a data de check-in (ddmmaa): ");
    scanf(" %[^\n]", novoHospede.entrada);

    printf("Digite a data de check-out (ddmmaa): ");
    scanf(" %[^\n]", novoHospede.saida);

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
        printf("Quarto: %s\n", hospedes[i].quarto);
        printf("Check-in: %c%c/%c%c/20%c%c\n", hospedes[i].entrada[0], hospedes[i].entrada[1], hospedes[i].entrada[2], hospedes[i].entrada[3], hospedes[i].entrada[4], hospedes[i].entrada[5]);
        printf("Check-out: %c%c/%c%c/20%c%c\n", hospedes[i].saida[0], hospedes[i].saida[1], hospedes[i].saida[2], hospedes[i].saida[3], hospedes[i].saida[4], hospedes[i].saida[5]);
        printf("\n");
    }
}

//Ordena os Hospedes pelo número do quarto
void sortHospedes(struct Hospede hospedes[], int numHospedes){
  int n1, n2;

  struct Hospede aux;
  for(int i=0; i<numHospedes-1; i++){
    for(int j=0; j<numHospedes-1-i; j++){
      //Converte o número do quarto para int 
      n1 = converteQuarto(hospedes, j);
      n2 = converteQuarto(hospedes, j+1);

      if(n1 > n2){
        aux = hospedes[j];
        hospedes[j] = hospedes[j+1];
        hospedes[j+1] = aux;
      }
    }
  }
}

//Função para exibir o status dos quartos
void exibirStatus(struct Hospede hospedes[]){
  int numQuarto=1;
  char dataIni[12];
  char dataFin[12];
  char auxStr1[4];
  char auxStr2[4];
  int n1, n2;
  /*
  printf("┌");
  printf("┐");
  printf("└");
  printf("┘");
  printf("─");
  printf("│");
  */

  system("clear");

  printf("Qual a data que deseja verificar a disponibilidade?\n");
  printf("Data inicial (ddmmaaa): ");
  getchar();
  fgets(dataIni, sizeof(dataIni), stdin);

  printf("Data final (ddmmaaa): ");
  getchar();
  fgets(dataFin, sizeof(dataFin), stdin);

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
        printf("%d", (i+1)*100+numQuarto);
        numQuarto+=2;
        printf("│");
      }
      printf("\n");

      if(h==1){
        numQuarto = 2;
      }

      for(int j=0; j<QUARTOS_ANDAR/2; j++){
        int quarto;

        printf("└");
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
                sortHospedes(agenda, numHospedes);
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

