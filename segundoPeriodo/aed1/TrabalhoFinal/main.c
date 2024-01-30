/*
TRABALHO FINAL DE AED1
Professora: Nádia Félix
Nomes: João Victor Lemes, Yasmin Moura

Sistema de Banco para o usuário final
*/

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
  imprimeClientes(head);

  fclose(arquivo);

  printf("============================\n");
  printf("===== BANCO DO CERRADO =====\n");
  printf("============================\n\n");

  bool flag1 = true;
  bool fez_login = false;
  while (flag1) {

    int opt;
    int id_user;
    printf("O QUE DESEJA FAZER?\n");
    printf("1 - CRIAR UMA CONTA\n");
    printf("2 - ACESSAR UMA CONTA EXISTENTE\n");
    printf("3 - SAIR\n");
    printf("OPÇÃO: ");
    scanf("%d", &opt);

    switch (opt){
      case (1):
        id_user = criarConta(&head);
        imprimeClientes(head);
        fez_login = true;
        break;
  //     case (2):
  //       index_user = login(clientes, numero_de_users);
        fez_login = true;
        break;
      case (3):
        flag1 = false;
        break;
      default:
        printf("Opção inválida\n");
    }

    if (fez_login == true) {
      bool flag2 = true;
      while (flag2) {
        printf("\n\nOlá User id: %d\n", id_user);
        printf("O QUE DESEJA FAZER?\n");
        printf("1 - EXIBIR SALDO\n");
        printf("2 - DEPÓSITO\n");
        printf("3 - TRANSFERÊNCIA\n");
        printf("4 - SAIR\n");
        printf("OPÇÃO: ");
        scanf("%d", &opt);
        switch (opt) {
  //         case(1):
  //           imprimirSaldo(clientes, index_user);
  //           break;
  //         case(2):
  //           depositarDinheiro(clientes, index_user);
  //           break;
  //         case(3):
  //           transferirDinheiro(clientes, index_user, numero_de_users);
  //           break;
          case(4):
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

    if (indexEmail(&(*head) ,temp_email) < 0) {
      break;
    }
    else if (indexEmail(&(*head), temp_email) >= 0) {
      printf("Já exite uma conta com esse email, utilize outro email\n");
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

// int login(cliente_t clientes[], int numero_de_users){
//   char temp_email[100];
//   char temp_senha[100];
//
//   while (true) {
//     printf("\nLogin\n");
//     printf("Email: ");
//     scanf("%s", temp_email);
//     getchar();
//     printf("Senha: ");
//     fgets(temp_senha, sizeof(temp_senha), stdin);
//     temp_senha[strcspn(temp_senha, "\n")] = '\0';
//
//     if (indexEmail(clientes, numero_de_users, temp_email) >= 0 && strcmp(clientes[indexEmail(clientes, numero_de_users, temp_email)].senha, temp_senha) == 0) {
//       return indexEmail(clientes, numero_de_users, temp_email);
//     }
//     else if (indexEmail(clientes, numero_de_users, temp_email) < 0 || strcmp(clientes[indexEmail(clientes, numero_de_users, temp_email)].senha, temp_senha) != 0) {
//       printf("Email ou  senha inválidos\n");
//     }
//   }
// }

void imprimirSaldo(cliente_t clientes[], int index_user){
  printf("============================\n");
  printf("Saldo: R$%.2Lf\n", clientes[index_user].saldo);
}

void depositarDinheiro(cliente_t clientes[], int index_user){
  printf("============================\n");
  printf("Valor: ");
  long double temp;
  scanf("%Lf", &temp);
  if (clientes[index_user].saldo + temp > LLONG_MAX || clientes[index_user].saldo + temp < LLONG_MIN) {
    printf("DEPÓSITO INVÁLIDO\n");
    return;
  }
  clientes[index_user].saldo += temp;
}

// void transferirDinheiro(cliente_t clientes[], int index_remetente, int numero_de_users){
//   char temp_email[100];
//   long double temp;
//   printf("============================\n");
//   printf("Valor do depósito: ");
//   scanf("%Lf", &temp);
//   printf("Email do destinatário: ");
//   getchar();
//   fgets(temp_email, sizeof(temp_email), stdin);
//   temp_email[strcspn(temp_email, "\n")] = '\0';
//
//   if (indexEmail(clientes, numero_de_users, temp_email) < 0 || temp > clientes[index_remetente].saldo) {
//     printf("Saldo insuficiente ou usuário de destino inexistente\n");
//     return;
//   }
//   int index_destino = indexEmail(clientes, numero_de_users, temp_email);
//
//   clientes[index_remetente].saldo -= temp;
//   clientes[index_destino].saldo += temp;
//
//   printf("Depósito de R$%.2Lf realizado com sucesso para %s\n", temp, clientes[index_destino].nome);
// }
