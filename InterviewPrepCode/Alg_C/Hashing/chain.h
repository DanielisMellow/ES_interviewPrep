#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {
  unsigned int key;
  char *value;
  struct node *next;
};
typedef struct node node;

// Function To Create a new node
node *createNode(unsigned int key, const char *value);

void sortedInsert(node **head_ref, unsigned int key, const char *value);

void printList(node *head);
node *search(node *head, int key);

void deleteNode(node **head_ref, unsigned int key);

int count(node *head);

void freeList(node *head_ref);
