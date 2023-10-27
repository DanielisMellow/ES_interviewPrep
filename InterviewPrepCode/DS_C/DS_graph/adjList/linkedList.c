#include "linkedList.h"
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function To Create a new node
node *createNode(unsigned int vertex) {
  node *newNode = (node *)malloc(sizeof(node));
  if (newNode == NULL) {
    printf("Failed Memory Allocation for new node\n");
    return NULL;
  }

  newNode->vertex = vertex;
  newNode->next = NULL;
  return newNode;
}

void insert(node **head_ref, unsigned int vertex) {
  node *new_node = createNode(vertex);
  if (new_node == NULL) {
    return;
  }

  node *currentNode = *head_ref;

  // To Deal if new node belongs at the begining
  if (*head_ref == NULL) {
    *head_ref = new_node;
    return;
  }

  while (currentNode->next != NULL) {
    currentNode = currentNode->next;
  }
  new_node->next = currentNode->next;
  currentNode->next = new_node;
}

void printList(node *head, int vertex) {
  if (head == NULL) {
    printf("[ ]\n");
  } else {

    printf("| %d | -> ", vertex);
    while (head != NULL) {
      if (head->next != NULL) {

        printf("[%d] -> ", head->vertex);
      } else {
        printf("[%d]", head->vertex);
      }
      head = head->next;
    }
    printf("\n");
  }
}

node *search(node *head, int vertex) {
  while (head != NULL) {
    if (head->vertex == vertex)
      return head;

    head = head->next;
  }

  return NULL;
}

void freeList(node *head_ref) {
  node *temp = NULL;

  while (head_ref) {
    temp = head_ref;
    head_ref = head_ref->next;
    free(temp);
  }
}

/* int main(int argc, char *argv[]) {

  node *head = NULL;
  int Arr[] = {
      1,
      2,
      3,
      4,
  };
  char *Value = "Dummy";
  int size = sizeof(Arr) / sizeof(Arr[0]);
  for (int i = 0; i < size; i++) {
    sortedInsert(&head, Arr[i], Value);
  }
  printList(head);

  return EXIT_SUCCESS;
} */
