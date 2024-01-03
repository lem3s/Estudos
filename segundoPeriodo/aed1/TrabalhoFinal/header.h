/*
TRABALHO FINAL DE AED1
Professora: Nádia Félix
Nomes: João Victor Lemes, Yasmin Moura

Sistema de Banco para o usuário final
*/

typedef struct{
    unsigned long int id;
    char nome[100];
    char email[100];
    char senha[100];
    long double saldo;
}cliente_t;

// Menu principal
void menu();

// Adiciona novo usuário
void criarConta();

// Verifica se a senha criada é forte
int verificarSenha();

// Exclui um usuário
void excluirConta();

// Verifica credenciais de acesso do usuário
void login();

// Mostra para o usuário o a seu saldo
void verificarSaldo();

// Transfere dinheiro de um usuário para o outro
void transferirDinheiro();
