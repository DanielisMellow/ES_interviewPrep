#include <iso646.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

struct Node {
  int data;
  struct Node *both;
};

typedef struct Node node;

struct List {
  node *head;
  node *tail;
};
typedef struct List list;

void init_list(list *ll) {
  ll->head = NULL;
  ll->tail = NULL;
}

bool is_empty(list *ll) { return ll->head == NULL; }

node *XOR(node *a, node *b) {
  uintptr_t xor_ptr = (uintptr_t)a ^ (uintptr_t)b;

  return (node *)xor_ptr;
}

node *create_node(int data) {
  node *new_node = (node *)malloc(sizeof(node));

  if (new_node == NULL) {
    return NULL;
  }

  new_node->data = data;

  return new_node;
}

void insert_at_head(list *ll, int data) {
  node *new_node = create_node(data);

  if (new_node == NULL) {
    return;
  }
  // New Nodes next
  new_node->both = XOR(NULL, ll->head);

  // First node in the linked list
  if (ll->head == NULL) {
    ll->tail = new_node;
    ll->head = new_node;
    return;
  }

  // update prev node's both
  ll->head->both = XOR(new_node, XOR(ll->head->both, NULL));
  ll->head = new_node;
}

void insert_at_tail(list *ll, int data) {
  node *new_node = create_node(data);
  // Failed to allocated memory for new node
  if (new_node == NULL) {
    return;
  }

  new_node->both = XOR(ll->tail, NULL);
  // IF the LL is empty
  if (ll->tail == NULL) {
    ll->head = new_node;
    ll->tail = new_node;
    return;
  }

  ll->tail->both = XOR(XOR(ll->tail->both, NULL), new_node);
  ll->tail = new_node;
}

void delete_from_head(list *ll) {
  // List is Empty
  if (ll->head == NULL) {
    return;
  }

  node *next = XOR(NULL, ll->head->both);

  // Check if list is empty after deleted node
  if (next != NULL) {
    next->both = XOR(ll->head, next->both);
  } else {
    ll->tail = NULL;
  }

  free(ll->head);
  ll->head = next;
}

void delete_from_tail(list *ll) {
  // list is empty
  if (ll->tail == NULL) {
    return;
  }

  node *prev = XOR(ll->tail->both, NULL);
  if (prev != NULL) {
    prev->both = XOR(ll->tail, prev->both);
  } else {
    ll->head = NULL;
  }

  free(ll->tail);
  ll->tail = prev;
}

void print_list_addr(list ll) {
  if (ll.head == NULL) {

    printf("NULL\n");
    return;
  }
  node *cur = ll.head;
  node *prev = NULL;
  node *next;

  while (cur) {
    printf("%p\n", cur);
    next = XOR(prev, cur->both);
    prev = cur;
    cur = next;
  }

  printf("NULL\n");
}
void print_list(list ll) {

  if (ll.head == NULL) {

    printf("NULL\n");
    return;
  }
  node *cur = ll.head;
  node *prev = NULL;
  node *next;

  printf("Head->");
  while (cur) {
    printf("[%d|*]<->", cur->data);
    next = XOR(prev, cur->both);
    prev = cur;
    cur = next;
  }

  printf("NULL\n");
}

void print_list_tail(list ll) {
  if (ll.tail == NULL) {

    printf("NULL\n");
    return;
  }
  node *cur = ll.tail;
  node *next = NULL;
  node *prev;

  printf("tail->");
  while (cur) {
    printf("[%d|*]<->", cur->data);
    prev = XOR(next, cur->both);
    next = cur;
    cur = prev;
  }

  printf("NULL\n");
}

void free_list(list *ll) {
  if (ll == NULL) {
    return;
  }
  node *prev = NULL;
  node *next;

  while (ll->head != NULL) {
    next = XOR(prev, ll->head->both);
    prev = ll->head;
    free(ll->head);
    printf("%p\n", prev);
    ll->head = next;
  }
  ll->tail = ll->head;
}

int main(int argc, char *argv[]) {

  list main_list;
  init_list(&main_list);

  for (int i = 0; i < 6; i++) {
    if (i % 2 == 0) {
      insert_at_head(&main_list, i);
    } else {
      insert_at_tail(&main_list, i);
    }

    print_list(main_list);
  }

  printf("\n\nDeleting Nodes:\n");

  for (int i = 0; i < 2; i++) {
    delete_from_head(&main_list);
    print_list(main_list);
  }

  for (int i = 0; i < 2; i++) {
    delete_from_tail(&main_list);
    print_list(main_list);
  }

  printf("\n\n");
  print_list_tail(main_list);
  free_list(&main_list);

  print_list(main_list);
  print_list_tail(main_list);

  return EXIT_SUCCESS;
}
