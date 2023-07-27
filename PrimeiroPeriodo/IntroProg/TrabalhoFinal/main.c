#include <stdio.h>
#include <string.h>

#define MAX_HOSPEDE 100

// Definição da estrutura hospede
struct Hospede {
    char nome[50];
    char email[100];
    char telefone[15];
};

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
        printf("\n");
    }
}

int main() {
    struct Hospede agenda[MAX_HOSPEDE];
    int numHospedes = 0;
    char opcao;

    do {
        printf("MENU:\n");
        printf("1 - Cadastrar novo hospede\n");
        printf("2 - Exibir hospedes cadastrados\n");
        printf("0 - Sair\n");
        printf("Escolha uma opção: ");
        scanf(" %c", &opcao);

        switch (opcao) {
            case '1':
                numHospedes = cadastrarHospede(agenda, numHospedes);
                break;
            case '2':
                exibirHospedes(agenda, numHospedes);
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

