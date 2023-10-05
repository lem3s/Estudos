#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define MAX_HOSPEDE 100
#define ANDARES 4
#define QUARTOS_ANDAR 20  //Apenas numeros pares
#define PRE_COMUM 200
#define PRE_EXEC 350

// Definição da estrutura hospede
struct Hospede {
    char nome[50];
    char email[100];
    char telefone[15];
    char quarto[8];
    char entrada[12];
    char saida[12];
};

//Funções para retornar os dados tempo

//Retorna o dia atual
int getDia(){
  time_t t = time(NULL);
  struct tm tm = *localtime(&t);

  return tm.tm_mday;
}

//Retorna o mes atual
int getMes(){
  time_t t = time(NULL);
  struct tm tm = *localtime(&t);

  return tm.tm_mon+1;
}

//Retorna o ano atual
int getAno(){
  time_t t = time(NULL);
  struct tm tm = *localtime(&t);

  return tm.tm_year+1900;
}

//Retorna a hora atual
int getHoras(){
  time_t t = time(NULL);
  struct tm tm = *localtime(&t);

  return tm.tm_hour;
}

//Funções para converter as informações recebidas de string para int, para facilitar comparações

//Retorna o quarto do hóspede i
int convQuarto(struct Hospede hospedes[], int i){
  char auxStr[4];

  auxStr[0] = hospedes[i].quarto[0];
  auxStr[1] = hospedes[i].quarto[1];
  auxStr[2] = hospedes[i].quarto[2];
  auxStr[3] = '\0';

  return atoi(auxStr);
}

//Retorna o dia de entrada do hóspede i
int convDiaEnt(struct Hospede hospedes[], int i){
  char auxStr[3];

  auxStr[0] = hospedes[i].entrada[0];
  auxStr[1] = hospedes[i].entrada[1];
  auxStr[2] = '\0';

  return atoi(auxStr);
} 

//Retorna o mes de entrada do hóspede i
int convMesEnt(struct Hospede hospedes[], int i){
  char auxStr[3];

  auxStr[0] = hospedes[i].entrada[2];
  auxStr[1] = hospedes[i].entrada[3];
  auxStr[2] = '\0';

  return atoi(auxStr);
} 

//Retorna o ano de entrada do hóspede i
int convAnoEnt(struct Hospede hospedes[], int i){
  char auxStr[5];

  auxStr[0] = hospedes[i].entrada[4];
  auxStr[1] = hospedes[i].entrada[5];
  auxStr[2] = hospedes[i].entrada[6];
  auxStr[3] = hospedes[i].entrada[7];
  auxStr[4] = '\0';

  return atoi(auxStr);
} 

//Retorna o dia de saída do hóspede i
int convDiaSai(struct Hospede hospedes[], int i){
  char auxStr[3];

  auxStr[0] = hospedes[i].saida[0];
  auxStr[1] = hospedes[i].saida[1];
  auxStr[2] = '\0';

  return atoi(auxStr);
} 

//Retorna o mes de saída do hóspede i
int convMesSai(struct Hospede hospedes[], int i){
  char auxStr[3];

  auxStr[0] = hospedes[i].saida[2];
  auxStr[1] = hospedes[i].saida[3];
  auxStr[2] = '\0';

  return atoi(auxStr);
} 

//Retorna o ano de saída do hóspede i
int convAnoSai(struct Hospede hospedes[], int i){
  char auxStr[5];

  auxStr[0] = hospedes[i].saida[4];
  auxStr[1] = hospedes[i].saida[5];
  auxStr[2] = hospedes[i].saida[6];
  auxStr[3] = hospedes[i].saida[7];
  auxStr[4] = '\0';

  return atoi(auxStr);
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

    printf("Digite a data de check-in (ddmmaaaa): ");
    scanf(" %[^\n]", novoHospede.entrada);

    printf("Digite a data de check-out (ddmmaaaa): ");
    scanf(" %[^\n]", novoHospede.saida);

    hospede[numHospedes] = novoHospede;

    printf("Hospede cadastrado com sucesso!\n");

    return numHospedes + 1;
}


//FUNÇÃO PARA PRECIFICAR ESTADIA:
void PrecoEstadia (){
    int dias, preco;
    char quarto[5];

    printf("Digite o quarto: ");
    scanf("%s", quarto);

    printf("Digite o número de dias: ");
    scanf("%d", &dias);

    switch(quarto[0]){
        
        case('1'):
            preco = dias * PRE_COMUM;
            break;
        
        case('2'):
            preco = dias * PRE_COMUM;
            break;
        
        case('3'):
            preco = dias * PRE_COMUM;
            break;

        case('4'):
            preco = dias * PRE_EXEC;
            break;
    }

    printf("O valor da estadia será: R$ %d.00\n", preco);
}

// Função para calcular os lucros em certo período
void calcularLucros(struct Hospede hospedes[], int numHospedes) {
    int lucroTotal = 0;
    char iniciostr[12], fimstr[12];
    int inicio, fim;
    int anoInicio, mesInicio, diaInicio, anoFim, mesFim, diaFim;

    printf("Digite a data inicial (ddmmaaaa): ");
    scanf("%s", iniciostr);
    inicio = atoi(iniciostr);

    printf("Digite a data final (ddmmaaaa): ");
    scanf("%s", fimstr);
    fim = atoi(fimstr);

    anoInicio = inicio%10000;
    inicio = inicio/10000;
    mesInicio = inicio%100;
    inicio = inicio/100;
    diaInicio = inicio%100;

    anoFim = fim%10000;
    fim = fim/10000;
    mesFim = fim%100;
    fim = fim/100;
    diaFim = fim%100;

    for (int i = 0; i < numHospedes; i++) {
        int diaEntrada = convDiaEnt(hospedes, i);
        int mesEntrada = convMesEnt(hospedes, i);
        int anoEntrada = convAnoEnt(hospedes, i);

        int diaSaida = convDiaSai(hospedes, i);
        int mesSaida = convMesSai(hospedes, i);
        int anoSaida = convAnoSai(hospedes, i);

        int numDias = (anoSaida - anoEntrada) * 365 + (mesSaida - mesEntrada) * 30 + (diaSaida - diaEntrada);
        int precoQuarto = (hospedes[i].quarto[0] - '0') <= 3 ? PRE_COMUM : PRE_EXEC;

        lucroTotal += numDias * precoQuarto;
    }

    printf("O lucro total neste período é de: %d reais\n", lucroTotal);
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
        printf("Check-in: %c%c/%c%c/%c%c%c%c\n", hospedes[i].entrada[0], hospedes[i].entrada[1], hospedes[i].entrada[2], hospedes[i].entrada[3], hospedes[i].entrada[4], hospedes[i].entrada[5], hospedes[i].entrada[6], hospedes[i].entrada[7]);
        printf("Check-out: %c%c/%c%c/%c%c%c%c\n", hospedes[i].saida[0], hospedes[i].saida[1], hospedes[i].saida[2], hospedes[i].saida[3], hospedes[i].saida[4], hospedes[i].saida[5], hospedes[i].saida[6], hospedes[i].saida[7]);
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
      n1 = convQuarto(hospedes, j);
      n2 = convQuarto(hospedes, j+1);

      if(n1 > n2){
        aux = hospedes[j];
        hospedes[j] = hospedes[j+1];
        hospedes[j+1] = aux;
      }
    }
  }
}

//Função para exibir o status dos quartos
void exibirStatus(struct Hospede hospedes[], int numHospedes){
  int numQuarto=1;
  char data[12];
  char auxStr1[3];
  char auxStr2[5];
  int dia, mes, ano;
  int flag=0;

  system("clear");

  /*
  printf("Qual a data que deseja verificar a disponibilidade (ddmmaaaa): ");
  getchar();
  fgets(data, sizeof(data), stdin);

  auxStr1[0] = data[0];
  auxStr1[1] = data[1];
  auxStr1[2] = '\0';
  dia = atoi(auxStr1);

  auxStr1[0] = data[2];
  auxStr1[1] = data[3];
  auxStr1[2] = '\0';
  mes = atoi(auxStr1);

  auxStr2[0] = data[4];
  auxStr2[1] = data[5];
  auxStr2[2] = data[6];
  auxStr2[3] = data[7];
  auxStr2[4] = '\0';
  ano = atoi(auxStr2);

  system("clear");
  */
  
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

      if(h==0){
        numQuarto = 1;
      }
      else if(h==1){
        numQuarto = 2;
      }

      for(int j=0; j<QUARTOS_ANDAR/2; j++){
        int quarto;

        printf("└");
        printf("─");

        for(int k=0; k<numHospedes; k++){
          /*
          if(convQuarto(hospedes, i) == (i+1)*100+numQuarto && dia >= convDiaEnt(hospedes, i) && dia <= convDiaSai(hospedes, i) && mes >= convMesEnt(hospedes, i) && mes <= convMesSai(hospedes, i) && ano >= convAnoEnt(hospedes, i) && ano <= convMesSai(hospedes, i)){
            printf("X");
            flag = 1;
            break;
          }
          */
          if(convQuarto(hospedes, k) == (i+1)*100+numQuarto){
            printf("X");
            flag = 1;
            break;
          }
        }
        if(flag == 0){
          printf("O");
        }
        numQuarto+=2;
        flag = 0;
        

        printf("─");
        printf("┘");
      }
      printf("\n");
      numQuarto = 2;
    }
  }

  printf("\nOcupado: X\nLivre: O\n");
  printf("Pressione Enter para continuar ");

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
        printf("4 - Calcular valor total da estadia\n");
        printf("5 - Calcular lucros\n");
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
                exibirStatus(agenda, numHospedes);
                break;
            case '4': 
                PrecoEstadia();
                break;
            case '5':
                calcularLucros(agenda, numHospedes);
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