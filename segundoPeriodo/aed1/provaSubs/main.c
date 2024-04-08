#include <stdio.h>
#include <stdlib.h>

typedef struct node{
  int value;
  struct node *next;
}node_t;

int adiciona_node(node_t **head, int value) {
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

int e_primo(int n) {
  if (n <= 1) {
    return 0;
  }
  for (int i = 2; i <= n; i++) {
    if (n % i == 0) {
      return 0;
    }
  }
  return 1;
}

int main() {
  node_t *head = NULL;

  int x;
  do {
    scanf("%d", &x);
    if (x >= 0) {
      adiciona_node(&head, x);
    }
    else {
      break;
    }
  } while (1);

  node_t *current = head;

  int numero_nodes = 0;
  while (current->next != NULL) {
    numero_nodes++; 
    current = current->next;
  }

  for (int i = 0; i <= numero_nodes; i++) {
    current = head;
    for (int k = 0; k < numero_nodes - i; k++) {
      current = current->next;
    }

    int dividendo = current->value, divisor = 0;
    while (dividendo > 1) {
        if (dividendo % divisor == 0) {
          printf("%d ", divisor);
          dividendo = dividendo / divisor;
        }

      divisor++;
    }
    printf("\n");
  }

  return 0;
}

