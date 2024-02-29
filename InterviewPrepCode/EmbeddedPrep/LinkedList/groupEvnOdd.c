#include "LinkedList.h"
#include <stdio.h>
#include <stdlib.h>

// gcc LinkedList.c groupEvnOdd.c -o a -Wall

void insertNode(list *ll, node *newNode) {
  newNode->next = ll->head;
  ll->head = newNode;
}

void groupEvenOddV1(list *ll) {

  if (ll->head == NULL) {
    return;
  }

  list even;
  even.head = NULL;
  list odd;
  odd.head = NULL;

  node *temp = ll->head;
  node *prev = NULL;
  int count = 1;

  while (temp != NULL) {
    prev = temp;
    temp = temp->next;

    if (count % 2 == 0) {
      insertNode(&even, prev);
    } else {
      insertNode(&odd, prev);
    }
    count++;
  }

  temp = odd.head;
  while (temp->next != NULL) {
    temp = temp->next;
  }
  temp->next = even.head;

  ll->head = odd.head;
}

void groupEvenOddV2(list *ll) {

  // return if list doesnt have atleast 2 elements
  if (ll->head == NULL || ll->head->next == NULL) {
    return;
  }

  node *odd = ll->head;
  node *odd_head = odd;

  node *even = ll->head->next;
  node *even_head = even;

  while (even && even->next) {

    odd->next = odd->next->next;
    even->next = even->next->next;

    odd = odd->next;
    even = even->next;
  }

  odd->next = even_head;
  ll->head = odd_head;
}

int main(int argc, char *argv[]) {

  list mainList;

  initList(&mainList);

  for (int i = 4; i > 0; i--) {
    addNode(&mainList, i);
    printList(mainList);
  }

  groupEvenOddV1(&mainList);
  printf("\n");
  printList(mainList);

  printf("\n");
  printf("\n");

  list mainList2;
  initList(&mainList2);

  for (int i = 4; i > 0; i--) {
    addNode(&mainList2, i);
    printList(mainList2);
  }

  groupEvenOddV2(&mainList2);
  printf("\n");
  printList(mainList2);

  return EXIT_SUCCESS;
}
