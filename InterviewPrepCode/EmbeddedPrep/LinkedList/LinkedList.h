#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

struct Node {
  int data;
  struct Node *next;
};
typedef struct Node node;

struct LinkedList {
  node *head;
};
typedef struct LinkedList list;

void initList(list *userList);
int isEmpty(list *userList);
node *createNode(int data);
void addNode(list *userList, int data);
int removeNode(list *userList);
void printList(list userList);
