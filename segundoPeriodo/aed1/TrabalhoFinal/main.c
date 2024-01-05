/*
TRABALHO FINAL DE AED1
Professora: Nádia Félix
Nomes: João Victor Lemes, Yasmin Moura

Sistema de Banco para o usuário final
*/

#include <stdio.h>
#include <stdlib.h>
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
  unsigned int numero_de_users = 0;
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
      fscanf(arquivo, "%lu,%99[^,],%99[^,],%99[^,],%Lf", &clientes[i].id, clientes[i].nome, clientes[i].email, clientes[i].senha, &clientes[i].saldo);
    }
  }
  fclose(arquivo);

  printf("============================\n");
  printf("===== BANCO DO CERRADO =====\n");
  printf("============================\n\n");

  int exit = 1;
  while (exit) {

    int opt;
    printf("O QUE DESEJA FAZER?\n");
    printf("1 - CRIAR UMA CONTA\n");
    printf("2 - ACESSAR UMA CONTA EXISTENTE\n");
    printf("3 - SAIR\n");
    printf("OPÇÃO: ");
    scanf("%d", &opt);

    switch (opt) {
      case (1):
        criarConta(clientes);
        break;

      case (2):
        login(clientes);
        break;

      case (3):
        exit = 0;
        break;

      default:
        printf("ERRO: Operação inválida\n");
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

void criarConta(cliente_t clientes[]){

}

void login(cliente_t clientes[]){

}
