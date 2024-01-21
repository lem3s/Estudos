#include <stdio.h>
#include <stdlib.h>

typedef struct node{
  int value;
  struct node *next;
}node_t;

int adiciona_inicio(node_t **head, int value) {
  if (*head == NULL) {
    (*head) = malloc(sizeof(node_t));
    (*head)->value = value;
    (*head)->next = NULL;

    return 0;
  }

  node_t *current = *head;
  current = malloc(sizeof(node_t));
  current->value = value;
  current->next = *head;

  *head = current;

  return 0;
}

int adiciona_final(node_t **head, int value) {
  if (*head == NULL) {
    (*head) = malloc(sizeof(node_t));
    (*head)->value = value;
    (*head)->next = NULL;
    return 0;
  }

  node_t *current = *head;
  while (current->next != NULL) {
    current = current->next;
  }

  current->next = malloc(sizeof(node_t));
  current = current->next;
  current->value = value;
  current->next = NULL;

  return 0;
}

int remover_inicio(node_t **head) {
  if (*head == NULL) {
    return -1;
  }

  node_t *current = *head;
  if ((*head)->next == NULL) {
    free(current);
    (*head) = NULL;
  }
  else if ((*head)->next != NULL) {
    *head = (*head)->next;
    free(current);
  }

  return 0;
}

int remover_final(node_t **head) {
  if (*head == NULL) {
    return -1;
  }

  node_t *current = *head;
  node_t *anterior = *head;
  while (current->next != NULL) {
    anterior = current;
    current = current->next;
  }

  anterior->next = NULL;
  free(current);

  return 0;
}

node_t* deleteUltimaOcorrencia(node_t **head, int item) {
  if (*head == NULL) {
    printf("A lista está vazia\n");
    return *head;
  }

  node_t *current = *head;
  node_t *ultimaOcorrencia = NULL;

  while (current != NULL) {
    if (current->value == item) {
      ultimaOcorrencia = current;
    }
    if (current != NULL) {
      current = current->next;
    }
  }

  if (ultimaOcorrencia == NULL) {
    printf("Item não está presente na lista\n");
    return *head;
  }

  current = *head;
  node_t *anterior = NULL;
  while (current != ultimaOcorrencia) {
    anterior = current;
    current = current->next;
  }

  printf("teste3\n");
  if (anterior != NULL) {
    anterior->next = current->next;
  }
  else if (anterior == NULL) {
    *head = NULL;
  }
  free(current);

  return *head;
}

int imprime_lista(node_t **head) {
  if (*head == NULL) {
    printf("LISTA VAZIA\n");
    return -1;
  }

  node_t *current = *head;
  do {
    printf("===========================\n");
    printf("VALUE: %d\n", current->value);
    printf("NEXT: %p\n", current->next);
    printf("===========================\n");
    if (current->next == NULL) {
      break;
    }
    else {
      current = current->next;
    }
  }while (1);

  return 0;
}

int main() {
  node_t *head = NULL;

  int flag = 1;
  while (flag) {
    int opcao;
    printf("O que deseja fazer?\n");
    printf("1) Adicionar node no inicio\n");
    printf("2) Adicionar node no final\n");
    printf("3) Remover node no inicio\n");
    printf("4) Remover node no final\n");
    printf("5) Imprimir todos os elementos da lista\n");
    printf("6) Sair\n");
    printf("7) deleteUltimaOcorrencia\n");
    printf("Opção: ");
    scanf("%d", &opcao);

    int temp;
    switch (opcao) {
      case (1):
        printf("Valor: ");
        scanf("%d", &temp);
        adiciona_inicio(&head, temp);
        break;
      case (2):
        printf("Valor: ");
        scanf("%d", &temp);
        adiciona_final(&head, temp);
        break;
      case (3):
        remover_inicio(&head);
        break;
      case (4):
        remover_final(&head);
        break;
      case (5):
        imprime_lista(&head);
        break;
      case (6):
        flag = 0;
        break;
      case (7):
        printf("Valor: ");
        scanf("%d", &temp);
        deleteUltimaOcorrencia(&head, temp);
        break;
      default:
        printf("Opção inválida!");
        break;
    }
    printf("\n");
  }


  return 0;
}
