#include "LinkedList.h"
#include <stdio.h>
#include <stdlib.h>

// gcc LinkedList.c removeKey.c -o a -Wall

int removeKey(list *ll, int key) {

  if (ll->head == NULL) {
    printf("List is Empty\n");
    return 0;
  }

  node *temp = ll->head;
  node *prev = NULL;
  if (temp->data == key) {
    ll->head = temp->next;
    free(temp);
    return 1;
  }

  while (temp != NULL && temp->data != key) {
    prev = temp;
    temp = temp->next;
  }

  if (temp != NULL) {
    prev->next = temp->next;
    free(temp);
    return 1;
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
  removeKey(&mainList, 3);
  printf("\n");
  printList(mainList);

  return EXIT_SUCCESS;
}
