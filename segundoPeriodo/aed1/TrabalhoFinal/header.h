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


// Adiciona novo usuário
void criarConta(cliente_t clientes[]);

// Verifica se a senha criada é forte
int verificarSenha();

void criptografiaSenha();

// Exclui um usuário
void excluirConta(cliente_t clientes[]);

// Verifica credenciais de acesso do usuário
void login(cliente_t clientes[]);

// Mostra para o usuário o a seu saldo
void verificarSaldo(cliente_t clientes[]);

// Transfere dinheiro de um usuário para o outro
void transferirDinheiro(cliente_t clientes[]);
