#include "LinkedList.h"
#include <stdio.h>

// gcc LinkedList.c reverseLL.c -o a -Wall

void reverseLL(list *ll) {
  if (ll->head == NULL) {
    // List is empty
    return;
  }
  node *a = ll->head;
  node *b = NULL;
  node *c = NULL;

  while (a != NULL) {
    b = a;
    a = a->next;
    b->next = c;
    c = b;
  }
  ll->head = b;
}

int main(int argc, char *argv[]) {

  list mainList;

  initList(&mainList);

  for (int i = 0; i < 5; i++) {
    addNode(&mainList, i);
    printList(mainList);
  }
  reverseLL(&mainList);
  printf("\n");
  printList(mainList);

  return EXIT_SUCCESS;
}
