/*
TRABALHO FINAL DE AED1
Professora: Nádia Félix
Nomes: João Victor Lemes, Yasmin Moura

Sistema de Banco para o usuário final
*/

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <limits.h>
#include "header.h"

int main(int argc, char *argv[]) {
  FILE *arquivo = fopen("dados.csv", "r");

  if (arquivo == NULL) {
    printf("ERRO: O arquivo de armazenamento de dados não existe\n");
    fclose(arquivo);

    arquivo = fopen("dados.csv", "w");
    printf("Arquivo de configuração criado\n");
  }
  fclose(arquivo);

  arquivo = fopen("dados.csv", "r");

  // Move o ponteiro para o final do arquivo para saber seu tamnho
  fseek(arquivo, 0, SEEK_END);
  long tamanho_arquivo = ftell(arquivo);
  fseek(arquivo, 0, SEEK_SET);

  // Tamanho 0 significa que ele está vazio
  int numero_de_users = 0;
  if (tamanho_arquivo != 0){
    char ch;

    // Conta quantas linhas o documento possui para
    // que possa ser alocado o tanto certo de memória sem haver desperdício
    while ((ch = fgetc(arquivo)) != EOF) {
      if (ch == '\n') {
        numero_de_users++;
      }
    }
  }

  fseek(arquivo, 0, SEEK_SET);

  // Aloca numero_de_users + 1 de memória para suportar os users existentes mais
  // a criação de um novo usuário caso ele ainda não possua conta

  cliente_t *head = NULL;
  if (numero_de_users > 0) {
    head = malloc(sizeof(cliente_t));
    fscanf(arquivo, "%lu,%99[^,],%99[^,],%99[^,],%Lf",
        &head->id, head->nome, head->email, head->senha, &head->saldo);
    head->next = NULL;

    for (int i = 0; i < numero_de_users - 1; i++) {
      cliente_t *current = head;
      while (current->next != NULL) {
        current = current->next;
      }
      current->next = malloc(sizeof(cliente_t));
      current = current->next;

      fscanf(arquivo, "%lu,%99[^,],%99[^,],%99[^,],%Lf",
                      &current->id, current->nome, current->email, current->senha, &current->saldo);
      current->next = NULL;
    }
  }

  fclose(arquivo);

  bool flag1 = true;
  printf("\e[1;1H\e[2J");
  while (flag1) {

    int opt;
    int id_user = -1;

    printf("============================\n");
    printf("===== BANCO DO CERRADO =====\n");
    printf("============================\n\n");
    printf("O QUE DESEJA FAZER?\n");
    printf("1 - CRIAR UMA CONTA\n");
    printf("2 - ACESSAR UMA CONTA EXISTENTE\n");
    printf("3 - SAIR\n");
    printf("OPÇÃO: ");
    scanf("%d", &opt);

    switch (opt){
      case (1):
        id_user = criarConta(&head);
        break;
      case (2):
        id_user = login(&head);
        break;
      case (3):
        flag1 = false;
        break;
      default:
        printf("Opção inválida\n");
    }

    if (id_user >= 0) {
      bool flag2 = true;
      printf("\e[1;1H\e[2J");
      while (flag2) {

        cliente_t *ponteiro_nome = head;
        while (ponteiro_nome->id != id_user) {
          ponteiro_nome = ponteiro_nome->next;
        }

        printf("\nOlá %s\n", ponteiro_nome->nome);
        printf("O QUE DESEJA FAZER?\n");
        printf("1 - EXIBIR SALDO\n");
        printf("2 - DEPÓSITO\n");
        printf("3 - SAQUE\n");
        printf("4 - TRANSFERÊNCIA\n");
        printf("5 - EXCLUIR CONTA\n");
        printf("6 - SAIR\n");
        printf("OPÇÃO: ");
        scanf("%d", &opt);
        switch (opt) {
          case(1):
            imprimirSaldo(&head, id_user);
            break;
          case(2):
            depositarDinheiro(&head, id_user);
            break;
          case(3):
            sacarDinheiro(&head, id_user);
            break;
          case(4):
            transferirDinheiro(&head, id_user);
            break;
          case(5):
            if (excluirConta(&head, id_user) == 0){
              printf("Conta excluída com sucesso\n");
              flag1 = false;
              flag2 = false;
            }
            break;
          case(6):
            flag1 = false;
            flag2 = false;
            break;
          default:
            printf("Opção inválida\n");
        }
      }
    }

  }


  arquivo = fopen("dados.csv", "w");


  cliente_t *current = head;
  do {
    fprintf(arquivo, "%lu,%s,%s,%s,%.2Lf\n", current->id, current->nome, current->email, current->senha, current->saldo);
    if (current->next == NULL) {
      break;
    }
    else {
      current = current->next;
    }
  }while (1);

  fclose(arquivo);

  return 0;
}

void imprimeClientes(cliente_t *head) {
  cliente_t *current = head;

  do {
    printf("===========================\n");
    printf("ID: %lu\n", current->id);
    printf("NOME: %s\n", current->nome);
    printf("EMAIL: %s\n", current->email);
    printf("SENHA: %s\n", current->senha);
    printf("SALDO: %Lf\n", current->saldo);
    printf("NEXT: %p\n", current->next);
    printf("===========================\n");
    if (current->next == NULL) {
      break;
    }
    else {
      current = current->next;
    }
  }while (1);
}

int criarConta(cliente_t **head){
  char temp_email[100];

  while (true) {
    printf("\nCriação de conta\n");
    printf("Email: ");
    scanf("%s", temp_email);

    if (indexEmail(&(*head), temp_email) >= 0) {
      printf("\e[1;1H\e[2J");
      printf("ERRO: Já exite uma conta com esse email, utilize outro email\n");
      return -1;
    }
    else if (indexEmail(&(*head), temp_email) < 0) {
      break;
    }
  }

  cliente_t *current = *head;
  cliente_t *anterior = *head;
  while (current->next != NULL){
    current = current->next;
    anterior = current;
  }
  current->next = malloc(sizeof(cliente_t));
  current = current->next;

  strcpy(current->email, temp_email);

  getchar();
  printf("Nome: ");
  fgets(current->nome, sizeof(current->nome), stdin);
  current->nome[strcspn(current->nome, "\n")] = '\0';

  printf("Senha: ");
  fgets(current->senha, sizeof(current->senha), stdin);
  current->senha[strcspn(current->senha, "\n")] = '\0';

  current->id = (anterior->id) + 1;
  current->saldo = 0.0;

  return current->id;
}

int login(cliente_t **head){
  char temp_email[100];
  char temp_senha[100];

  printf("\nLogin\n");
  printf("Email: ");
  scanf("%s", temp_email);
  getchar();
  printf("Senha: ");
  fgets(temp_senha, sizeof(temp_senha), stdin);
  temp_senha[strcspn(temp_senha, "\n")] = '\0';

  if (indexEmail(&(*head), temp_email) >= 0 && indexEmail(&(*head), temp_email) == indexSenha(&(*head), temp_senha)) {
    cliente_t *current = *head;

    for (int i = 0; i < indexEmail(&(*head), temp_email); i++) {
      current = current->next;
    }
    return current->id;
  }
  else if(indexEmail(&(*head), temp_email) < 0 || indexEmail(&(*head), temp_email) != indexSenha(&(*head), temp_senha)) {
    printf("\e[1;1H\e[2J");
    printf("ERRO: Email ou  senha inválidos\n");
    return -1;
  }
  return -1;
}

void imprimirSaldo(cliente_t **head, int id_user){

  cliente_t *current = *head;
  while (current->id != id_user) {
    current = current->next;
  }

  printf("============================\n");
  printf("Saldo: R$%.2Lf\n", current->saldo);
  printf("============================\n");
}

void depositarDinheiro(cliente_t **head, int id_user){
  printf("============================\n");
  printf("Valor: R$");
  long double temp;
  scanf("%Lf", &temp);

  cliente_t *current = *head;
  while (current->id != id_user) {
    current = current->next;
  }

  if (current->saldo + temp > LLONG_MAX || current->saldo + temp < LLONG_MIN) {
    printf("DEPÓSITO INVÁLIDO\n");
    return;
  }
  current->saldo += temp;
  printf("============================\n");
}

void sacarDinheiro(cliente_t **head, int id_user){
  printf("============================\n");
  printf("Valor: R$");
  long double temp;
  scanf("%Lf", &temp);

  cliente_t *current = *head;
  while (current->id != id_user) {
    current = current->next;
  }

  if (current->saldo - temp < LLONG_MIN) {
    printf("DEPÓSITO INVÁLIDO\n");
    return;
  }
  current->saldo -= temp;
  printf("============================\n");
}

void transferirDinheiro(cliente_t **head, int id_user){
  char temp_email[100];
  long double temp;
  printf("============================\n");
  printf("Valor do depósito: R$");
  scanf("%Lf", &temp);
  printf("Email do destinatário: ");
  getchar();
  fgets(temp_email, sizeof(temp_email), stdin);
  temp_email[strcspn(temp_email, "\n")] = '\0';

  cliente_t *current_remetente = *head;
  while (current_remetente->id != id_user) {
    current_remetente = current_remetente->next;
  }

  if (indexEmail(&(*head), temp_email) < 0) {
    printf("Usuário de destino inexistente\n");
    return;
  }
  else if (temp > current_remetente->saldo) {
    printf("Saldo insuficiente\n");
    return;
  }

  cliente_t *current_destinatario = *head;
  while (strcmp(current_destinatario->email, temp_email) != 0) {
    current_destinatario = current_destinatario->next;
  }

  current_remetente->saldo -= temp;
  current_destinatario->saldo += temp;

  printf("Depósito de R$%.2Lf realizado com sucesso para %s\n", temp, current_destinatario->nome);
  printf("============================\n");
}

int excluirConta(cliente_t **head, int id_user){
  printf("============================\n");
  bool flag = true;
  while (flag) {
    char opt;
    printf("Tem certeza que deseja excluir sua conta [S/N]: ");
    getchar();
    scanf("%c", &opt);
    opt = toupper(opt);
    switch (opt) {
      case('S'):
        flag = false;
        break;
      case('N'):
        return -1;
      default:
        printf("Opção inválida\n");
        break;
    }
  }

  cliente_t *current = *head;
  cliente_t *anterior = *head;
  while (current->id != id_user) {
    anterior = current;
    current = current->next;
  }

  anterior->next = current->next;
  free(current);

  return 0;
}

int indexEmail(cliente_t **head, char email[]){
  int i = 0;
  cliente_t *current = *head;
  do {
    if (strcmp(current->email, email) == 0) {
      return i;
    }
    else {
      i++;
      current = current->next;
    }
  }while (current != NULL);

  return -1;
}

int indexSenha(cliente_t **head, char senha[]){
  int i = 0;
  cliente_t *current = *head;
  do {
    if (strcmp(current->senha, senha) == 0) {
      return i;
    }
    else {
      i++;
      current = current->next;
    }
  }while (current != NULL);

  return -1;
}
