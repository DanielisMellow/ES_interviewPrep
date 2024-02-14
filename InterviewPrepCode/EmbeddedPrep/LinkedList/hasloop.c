#include "LinkedList.h"

int hasLoop(list userList) {
  if (userList.head == NULL) {
    printf("Empty List\n");
    return -1;
  }

  node *hare = userList.head;
  node *tortoise = userList.head;

  while (hare->next != NULL && hare != NULL) {

    tortoise = tortoise->next; // Move tortoise one step
    hare = hare->next->next;   // Move hare two steps

    if (tortoise == hare) {
      return 1;
    }
  }

  return 0;
}

node *startLoopNode(node *head) {
  node *tortoise = head;
  node *hare = head;

  while (hare != NULL && hare->next != NULL) {
    tortoise = tortoise->next; // Move tortoise one step
    hare = hare->next->next;   // Move hare two steps

    if (tortoise == hare)
      break; // loop found
  }

  if (hare != tortoise) {
    return NULL;
  }

  tortoise = head;

  while (tortoise != hare) {
    tortoise = tortoise->next;
    hare = hare->next;
  }

  return tortoise; // loop not found
}
