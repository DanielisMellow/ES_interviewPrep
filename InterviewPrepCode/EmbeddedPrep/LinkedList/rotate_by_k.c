#include <stdio.h>
#include <stdlib.h>
// gcc rotate_by_k.c -o file -Wall
typedef struct node {
  int data;
  struct node *next;
} node;

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

void rotate_by_k(node **head, int k) {
  if (*head == NULL) {
    return;
  }
  node *last = *head;

  while (last->next != NULL) {
    last = last->next;
  }
  last->next = *head;

  for (int i = 0; i < k; i++) {
    last = last->next;
    *head = (*head)->next;
  }
  last->next = NULL;
}

node *rotate_by_kV2(node *head, int k) {
  if (head == NULL) {
    return NULL;
  }
  node *last = head;

  while (last->next != NULL) {
    last = last->next;
  }
  last->next = head;

  for (int i = 0; i < k; i++) {
    last = last->next;
    head = (head)->next;
  }
  last->next = NULL;

  return head;
}

int main(void) {
  node *head1 = NULL;
  for (int i = 1; i <= 3; i++) {
    add_node(&head1, i * 10);
  }

  printf("list:\n");
  print_list(head1);
  printf("\n\n");

  rotate_by_k(&head1, 1);
  printf("list after Rotation:\n");
  print_list(head1);
  printf("\n\n");

  return 0;
}
