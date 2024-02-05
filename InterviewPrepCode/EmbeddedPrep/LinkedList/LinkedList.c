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

int hasLoop(list userList) {
  if (userList.head == NULL) {
    printf("Empty List\n");
    return -1;
  }

  node *hare = userList.head;
  node *tortoise = userList.head;

  while (hare->next == NULL && hare != NULL) {

    tortoise = tortoise->next; // Move tortoise one step
    hare = hare->next->next;   // Move hare two steps

    if (tortoise == hare) {
      return 1;
    }
  }

  return 0;
}

int main(int argc, char *argv[]) {

  list mainList;
  initList(&mainList);

  for (int i = 0; i < 5; i++) {
    addNode(&mainList, i);
    printList(mainList);
  }

  for (int i = 0; i < 5; i++) {
    removeNode(&mainList);

    printList(mainList);
  }

  return EXIT_SUCCESS;
}
