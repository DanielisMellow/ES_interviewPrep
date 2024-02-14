#include "LinkedList.h"
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

void initList(list *userList) { userList->head = NULL; }
int isEmpty(list *userList) { return userList->head == NULL; }

node *createNode(int data) {
  node *newNode = (node *)malloc(sizeof(node));
  if (newNode == NULL) {
    printf("Failed to allocate mem for node\n");
    return NULL;
  }

  newNode->data = data;
  newNode->next = NULL;

  return newNode;
}

void addNode(list *userList, int data) {
  node *newNode = createNode(data);

  if (newNode == NULL) {
    return;
  }

  newNode->next = userList->head;
  userList->head = newNode;
}

int removeNode(list *userList) {
  if (isEmpty(userList))
    return INT_MIN;

  node *temp = userList->head;
  int removedData = temp->data;
  userList->head = temp->next;

  free(temp);
  return removedData;
}

void printList(list userList) {
  node *temp = userList.head;
  while (temp != NULL) {
    printf("[ %d ]->", temp->data);
    temp = temp->next;
  }

  printf("NULL \n");
}
