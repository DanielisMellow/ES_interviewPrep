#include <stdio.h>
#include <stdlib.h>
// gcc merge_sorted_lists.c -o file -Wall
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

node *merge_sorted(node *head1, node *head2) {
  // checks if either list is emtpy from start
  if (!(head1)) {
    return head2;
  } else if (!(head2)) {
    return head1;
  }

  // two pointers for the same resulting merged list
  // merged_head to be returned
  // merged_tail used to adding new nodes
  node *merged_head = NULL;
  node *merged_tail = NULL;

  // preliminary check to know where merged list should start
  if (head1->data <= head2->data) {
    merged_head = head1;
    head1 = head1->next;
  } else {
    merged_head = head2;
    head2 = head2->next;
  }
  merged_tail = merged_head;

  // actual loop that adds nodes to merged list
  node *temp = NULL;
  while (head1 != NULL && head2 != NULL) {
    if (head1->data <= head2->data) {
      temp = head1;
      head1 = head1->next;
    } else {
      temp = head2;
      head2 = head2->next;
    }
    // adds temp to the list
    merged_tail->next = temp;
    // moves to current end of list
    merged_tail = temp;
  }

  // if only one list ended, check which one
  // in order to add remaining nodes to merged list
  if (!(head1)) {
    merged_tail->next = head2;
  } else if (!(head2)) {
    merged_tail->next = head1;
  }

  // return merged list
  return merged_head;
}

node *merge_sorted_V2(node *head1, node *head2) {
  node *dummy = (node *)malloc(sizeof(node));
  if (dummy == NULL) {
    return NULL;
  }
  node *tail = dummy;

  while (head1 != NULL && head2 != NULL) {
    if (head1->data < head2->data) {
      tail->next = head1;
      head1 = head1->next;
    } else {
      tail->next = head2;
      head2 = head2->next;
    }
    tail = tail->next;
  }

  if (!(head1)) {
    tail->next = head2;
  } else if (!(head2)) {
    tail->next = head1;
  }

  node *finalHead = dummy->next;
  free(dummy);
  return finalHead;
}

int main(void) {
  node *head1 = NULL;
  node *head2 = NULL;
  for (int i = 0; i < 8; i++) {
    i % 2 == 0 ? add_node(&head1, i) : add_node(&head2, i);
  }

  add_node(&head1, 8);
  add_node(&head1, 9);
  add_node(&head1, 10);

  printf("First list.\n");
  print_list(head1);
  printf("\n");
  printf("Second list.\n");
  print_list(head2);
  printf("\n\n");

  node *merged_list = NULL;

  printf("Merged List.\n");
  merged_list = merge_sorted_V2(head1, head2);

  print_list(merged_list);
  return 0;
}
