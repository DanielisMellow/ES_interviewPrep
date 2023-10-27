#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {
  unsigned int vertex;
  struct node *next;
};
typedef struct node node;

// Function To Create a new node
node *createNode(unsigned int vertex);

void insert(node **head_ref, unsigned int vertex);

void printList(node *head, int vertex);
node *search(node *head, int vertex);

void deleteNode(node **head_ref, unsigned int vertex);

int count(node *head);

void freeList(node *head_ref);
