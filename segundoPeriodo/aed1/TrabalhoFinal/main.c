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
#include "header.h"


int main() {
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

  printf("### Arquivo lido com sucesso - numero de users: %u\n", numero_de_users);
  fseek(arquivo, 0, SEEK_SET);

  // Aloca numero_de_users + 1 de memória para suportar os users existentes mais
  // a criação de um novo usuário caso ele ainda não possua conta
  cliente_t clientes[numero_de_users + 1];

  if (numero_de_users > 0) {
    for (int i = 0; i < numero_de_users; i++) {
      fscanf(arquivo, "%lu,%99[^,],%99[^,],%99[^,],%Lf",
                      &clientes[i].id, clientes[i].nome, clientes[i].email, clientes[i].senha, &clientes[i].saldo);
    }
  }
  fclose(arquivo);

  printf("============================\n");
  printf("===== BANCO DO CERRADO =====\n");
  printf("============================\n\n");

  bool flag = true;
  bool criouConta = false;
  bool fezLogin = false;
  while (flag) {

    int opt;
    printf("O QUE DESEJA FAZER?\n");
    printf("1 - CRIAR UMA CONTA\n");
    printf("2 - ACESSAR UMA CONTA EXISTENTE\n");
    printf("3 - SAIR\n");
    printf("OPÇÃO: ");
    scanf("%d", &opt);

    switch (opt){
      case (1):
        criarConta(clientes, numero_de_users);
        numero_de_users++;
        break;
      case (2):
        login(clientes);
        break;
      case (3):
        flag = false;
        break;
    }

  }

  // TODO: Adicionar verificação de criação de conta para salvar a conta criada
  arquivo = fopen("dados.csv", "w");
  for (int i = 0; i < numero_de_users; i++) {
    fprintf(arquivo, "%lu,%s,%s,%s,%.2Lf\n", clientes[i].id, clientes[i].nome, clientes[i].email, clientes[i].senha, clientes[i].saldo);
  }

  fclose(arquivo);

  return 0;
}

void criarConta(cliente_t clientes[], int numero_de_users){
  while (true) {
    char temp_email[100];

    while (true) {
      printf("\nCriação de conta\n");
      printf("Email: ");
      scanf("%s", temp_email);

      if (credenciaisExistem(clientes, numero_de_users, temp_email) == false) {
        break;
      }
      else if (credenciaisExistem(clientes, numero_de_users, temp_email) == true) {
        printf("Já exite uma conta com esse email, utilize outro email\n");
      }
    }
    printf("Nome: ");
    fgets(clientes[numero_de_users].nome, sizeof(clientes[numero_de_users].nome), stdin);

    printf("Senha: ");
    fgets(clientes[numero_de_users].senha, sizeof(clientes[numero_de_users].senha), stdin);
  }
}

bool credenciaisExistem(cliente_t clientes[], int numero_de_users, char email[]){
  for (int i = 0; i < numero_de_users; i++) {
    if (strcmp(clientes[i].email, email) == 0) {
      return false;
    }
  }
  return true;
}

void login(cliente_t clientes[]){

}
