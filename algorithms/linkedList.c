#include <stdio.h>
#include <stdlib.h>

typedef struct node{
  int value;
  struct node *next;
}node_t;

void inicia_lista(node_t *head) {
  head =(node_t*) malloc(sizeof(node_t));

  head->value = 0;
  head->next = NULL;
}

void adiciona_nodes(int x_nodes, node_t *head) {
  node_t *current = head;
  if (head == NULL) {
    printf("HEAD == NULL\n");
    return;
  }

  while (current->next != NULL) {
    current = current->next;
  }

  for (int i = 0; i < x_nodes; i++) {
    current->next = malloc(sizeof(node_t));
    current = current->next;
    current->value = i;
  }

  current->next = NULL;
}

void imprime_lista(node_t *head) {
  node_t *current;
  int i = 0;
  while (current != NULL){
    printf("======================\n");
    printf("ITEM: %d\n", i++); 
    printf("VALUE: %d\n", current->value); 
    printf("NEXT: %p\n", current->next);
    printf("======================\n");

    current = current->next;
  }
}

int main() {
  node_t *head = NULL;
  head = malloc(sizeof(node_t));
  head->value = 123;
  head->next = NULL;

  printf("Lista Criada\n");

  int x_nodes;
  printf("Quantos nodes deseja criar: ");
  scanf("%d", &x_nodes);
  adiciona_nodes(x_nodes, head);
  printf("Nodes adicionados a lista\n");

  imprime_lista(head);

  return 0;
}
