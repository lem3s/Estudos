/*
TRABALHO FINAL DE AED1
Professora: Nádia Félix
Nomes: Joao Victor Lemes, Yasmin Moura

Sistema de Banco
*/

typedef struct{
    char nome[100];
    int id;
    char cpf[12];
    char senha[100];
    double saldo;
}cliente_t;

void menu();

void criarConta();

void excluirConta();

void login();

void verificarSaldo();

void transferirDinheiro();