#include <stdio.h>
#include <stdlib.h>

struct Node {
  int data;
  struct Node *next;
};
typedef struct Node node;

void add_node(node **head, int data) {
  node *new_node;
  if ((new_node = malloc(sizeof(node))) == NULL) {
    return;
  }
  new_node->data = data;

  if (*head == NULL) {
    new_node->next = *head;
    *head = new_node;
  }
  node *curr = *head;
  while (curr->next != NULL) {
    curr = curr->next;
  }
  curr->next = new_node;
  new_node->next = NULL;
}

void print_list(node *head) {
  if (head == NULL) {
    return;
  }

  while (head != NULL) {
    printf("[ %d ] -> ", head->data);
    head = head->next;
  }
  printf("NULL\n");
}

void reverse_in_blocks_of_k(node **head_ref, int k) {
  if (*head_ref == NULL) {
    return;
  }

  node *a = *head_ref;
  node *a_prime = NULL;
  node *b = NULL;
  node *c = NULL;

  while (a != NULL) {

    a_prime = a;

    for (int i = 0; i < k - 1; i++) {
      if (a->next == NULL) {
        break;
      }
      a = a->next;
    }

    b = a;
    a = a->next;

    b->next = c;
    c = a_prime;
  }

  *head_ref = c;
}

node *reverse_in_blocks_of_kV2(node *head_ref, int k) {

  if (head_ref == NULL) {
    return NULL;
  }

  node *a = head_ref;
  node *b = NULL;
  node *c = NULL;

  int count = 0;
  while (a != NULL && count < k) {

    b = a;
    a = a->next;
    b->next = c;
    c = b;

    count++;
  }

  if (a != NULL) {

    head_ref->next = reverse_in_blocks_of_kV2(a, k);
  }

  return c;
}

int main(int argc, char *argv[]) {

  node *head = NULL;
  node *head2 = NULL;
  for (int i = 1; i <= 7; i++) {
    add_node(&head, i);
    add_node(&head2, i);
  }
  print_list(head);

  reverse_in_blocks_of_k(&head, 2);
  print_list(head);

  head2 = reverse_in_blocks_of_kV2(head2, 2);
  print_list(head2);
  return EXIT_SUCCESS;
}
