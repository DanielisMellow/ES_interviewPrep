#include "LinkedList.h"
#include "stdio.h"
#include <stdlib.h>

// gcc LinkedList.c removeNthFromEnd.c -o a -Wall

// Remove nth node from end of the list
int removeNthFromEnd(list *ll, int n) {
  if (ll == NULL) {
    // list is empty return error
    return -1;
  }

  int length = 0;
  node *tmpA = ll->head;

  while (tmpA != NULL) {
    tmpA = tmpA->next;
    length++;
  }

  tmpA = ll->head;
  node *tmpB = ll->head;
  int target = length - n;
  int data;

  if (target == 0) {
    data = tmpA->data;
    ll->head = tmpA->next;
    free(tmpA);
    return data;
  }

  for (int i = 0; i < target; i++) {
    tmpB = tmpA;
    tmpA = tmpA->next;
  }
  if (target > 0) {
    data = tmpA->data;
    tmpB->next = tmpA->next;
    free(tmpA);
    return data;
  }
  return -1;
}

int main(int argc, char *argv[]) {

  list mainList;

  initList(&mainList);

  for (int i = 0; i < 5; i++) {
    addNode(&mainList, i);
    printList(mainList);
  }

  int targetNode = 2;
  removeNthFromEnd(&mainList, targetNode);
  printf("\nRemoving node %d from the end:\n", targetNode);
  printList(mainList);

  return EXIT_SUCCESS;
}
