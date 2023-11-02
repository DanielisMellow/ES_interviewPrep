#include "chain.h"
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function To Create a new node
node *createNode(unsigned int key, const char *value) {
  node *newNode = (node *)malloc(sizeof(node));
  if (newNode == NULL) {
    printf("Failed Memory Allocation for new node\n");
    return NULL;
  }

  newNode->key = key;
  newNode->value = strdup(value);
  newNode->next = NULL;
  return newNode;
}

void sortedInsert(node **head_ref, unsigned int key, const char *value) {
  node *new_node = createNode(key, value);
  if (new_node == NULL) {
    return;
  }

  node *currentNode = *head_ref;

  // To Deal if new node belongs at the begining
  if (*head_ref == NULL || key < (*head_ref)->key) {
    *head_ref = new_node;
    return;
  }

  while (currentNode->next && new_node->key > currentNode->next->key) {
    currentNode = currentNode->next;
  }
  new_node->next = currentNode->next;
  currentNode->next = new_node;
}

void printList(node *head) {
  if (head == NULL) {
    printf("[ ]\n");
  } else {

    printf("[*] -> ");
    while (head != NULL) {

      printf("[%d|%s] -> ", head->key, head->value);
      head = head->next;
    }
    printf("[ ]\n");
  }
}

node *search(node *head, int key) {
  while (head != NULL && key >= head->key) {
    if (head->key == key)
      return head;

    head = head->next;
  }

  return NULL;
}

void deleteNode(node **head_ref, unsigned int key) {
  node *temp = *head_ref;
  node *prev = NULL;

  // Deleting First Node
  if (temp != NULL && key == temp->key) {
    *head_ref = temp->next;
    free(temp);
    return;
  }

  while (temp != NULL && key > temp->key) {
    prev = temp;
    temp = temp->next;
  }

  // Dealing with the case of not finding the key
  if (temp == NULL || temp->key != key) {
    printf("Key not found in linked list\n");
    return;
  }

  prev->next = temp->next;
  free(temp);
}

int count(node *head) {
  int count = 0;
  while (head != NULL) {
    count++;
    head = head->next;
  }

  return count;
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
