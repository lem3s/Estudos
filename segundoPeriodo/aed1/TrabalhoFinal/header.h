/*
TRABALHO FINAL DE AED1
Professora: Nádia Félix
Nomes: João Victor Lemes, Yasmin Moura

Sistema de Banco para o usuário final
*/

typedef struct cliente{
    unsigned long int id;
    char nome[100];
    char email[100];
    char senha[100];
    long double saldo;
    struct cliente *next;
}cliente_t;

void imprimeClientes(cliente_t *head);

// Adiciona novo usuário
int criarConta(cliente_t **head);

int login(cliente_t **head);

// Mostra para o usuário o a seu saldo
void imprimirSaldo(cliente_t **head, int id_user);

void depositarDinheiro(cliente_t **head, int id_user);

void sacarDinheiro(cliente_t **head, int id_user);

// Transfere dinheiro de um usuário para o outro
void transferirDinheiro(cliente_t **head, int id_user);

// Exclui um usuário
int excluirConta(cliente_t **head, int id_user);

int indexSenha(cliente_t **head, char senha[]);
int indexEmail(cliente_t **head, char email[]);
