#include <stdio.h>
#include <stdlib.h>

// gcc insert_cyclic.c -o file -Wall
struct Node {
  int data;
  struct Node *next;
};

typedef struct Node node;

void add_node(node **head, int data) {
  node *new_node = (node *)malloc(sizeof(node));
  if (new_node == NULL) {
    return;
  }
  new_node->data = data;

  if (*head == NULL) {
    new_node->next = *head;
    *head = new_node;
    return;
  }

  node *cur = *head;
  while (cur->next != NULL) {
    cur = cur->next;
  }
  new_node->next = NULL;
  cur->next = new_node;
}

void print_cyclic_list(node *head) {
  node *cur = head;
  while (cur->next != head) {
    printf("[%d|*] -> ", cur->data);
    cur = cur->next;
  }
  printf("[%d|*]\n", cur->data);
}

node *create_node(int data) {
  node *new_node = (node *)malloc(sizeof(node));
  if (!(new_node)) {
    return NULL;
  }

  new_node->next = NULL;
  new_node->data = data;
  return new_node;
}
node *cyclic_insert(node *head, int data) {
  // create a new node make
  node *new_node = create_node(data);
  if (!(new_node)) {
    return head;
  }
  new_node->data = data;
  // first node in the list
  if (!(head)) {
    new_node->next = new_node;
    head = new_node;
    return head;
  }
  // node data is smaller than heads data
  if (new_node->data <= head->data) {
    node *cur = head;
    while (cur->next != head) {

      cur = cur->next;
    }
    cur->next = new_node;

    new_node->next = head;
    head = new_node;
    return head;
  }

  node *cur = head;
  while (new_node->data > cur->next->data && cur->next != head) {
    cur = cur->next;
  }

  new_node->next = cur->next;
  cur->next = new_node;
  return head;
}

node *cyclic_insert_sort(node *head, node *new_node) {
  // check if list is empty if it is,
  // make new node head and next is itself
  if (!(head)) {
    new_node->next = new_node;
    head = new_node;
    return head;
  }
  // at least one node in the list
  // a points to head we use a's next in order
  // to have a at the last node (1 before head)
  node *a = head;
  while (a->next != head) {
    // if at any point in traversing the list, the new node's
    // correct spot is in between a and a->next, then add it and return
    if (a->next->data > new_node->data && a->data < new_node->data) {
      new_node->next = a->next;
      a->next = new_node;
      return head;
    }
    // keep traversing
    a = a->next;
  }
  // a is now 1 before head (at the end) if new node is less
  // than head, then new node should be the new head
  if (head->data > new_node->data) {
    new_node->next = head;
    a->next = new_node;
    head = new_node;
    return head;
  }
  // if we made it this far, then new node belongs at the end of the list
  new_node->next = a->next;
  a->next = new_node;
  return head;
}

int main(int argc, char *argv[]) {
  node *head = NULL;
  // Adding Nodes
  for (int i = 1; i < 11; i += 2) {
    head = cyclic_insert(head, i);
  }

  print_cyclic_list(head);
  printf("\n");

  head = cyclic_insert(head, 6);
  print_cyclic_list(head);

  head = cyclic_insert(head, 0);
  print_cyclic_list(head);

  head = cyclic_insert(head, 10);
  print_cyclic_list(head);

  return EXIT_SUCCESS;
}
