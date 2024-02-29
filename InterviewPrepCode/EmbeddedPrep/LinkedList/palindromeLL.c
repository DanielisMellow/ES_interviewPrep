
#include "LinkedList.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// gcc LinkedList.c palindromeLL.c -o a -Wall

bool isPalindrome(list ll) {
  if (ll.head == NULL) {
    return false;
  }

  node *L = ll.head;
  node *R = ll.head;

  int length = 0;
  while (L != NULL) {
    L = L->next;
    length++;
  }

  L = ll.head;
  printf("%d : %d\n", L->data, R->data);
  for (int i = 0; i < length / 2; i++) {

    printf("Outer: %d : %d\n", L->data, R->data);
    for (int j = i; j < length - i - 1; j++) {

      R = R->next;
      printf("Inner: %d : %d\n", L->data, R->data);
    }
    if (L->data != R->data) {
      printf("%d : %d\n", L->data, R->data);
      return false;
    }
    L = L->next;
    R = L;
  }
  return true;
}

bool isPalindromeV2(list ll) {
  node *temp = ll.head;
  int count = 0;
  while (temp != NULL) {
    temp = temp->next;
    count++;
  }

  int *A = (int *)malloc(count * sizeof(int));

  for (int i = 0; i < count; i++) {
    A[i] = ll.head->data;
    ll.head = ll.head->next;
  }

  int i = 0;
  int j = count - 1;

  while (i < j) {

    printf("%d\t%d\n", A[i], A[j]);
    if (A[i] != A[j]) {
      free(A);
      return false;
    }
    i++;
    j--;
  }

  free(A);
  return true;
}

// Initial parameters to this function are &head and head
bool isPalindromeUtil(node **left, node *right) {
  /* stop recursion when right becomes NULL */
  if (right == NULL)
    return true;

  /* If sub-list is not palindrome then no need to
  check for current left and right, return false */
  bool isp = isPalindromeUtil(left, right->next);
  if (isp == false)
    return false;

  /* Check values at current left and right */
  bool isp1 = (right->data == (*left)->data);

  /* Move left to next node */
  *left = (*left)->next;

  return isp1;
}

// A wrapper over isPalindromeUtil()
bool isPalindromeV3(list ll) { return isPalindromeUtil(&ll.head, ll.head); }

int main(int argc, char *argv[]) {

  list mainList;

  initList(&mainList);

  addNode(&mainList, 1);
  addNode(&mainList, 2);
  addNode(&mainList, 3);
  addNode(&mainList, 4);
  addNode(&mainList, 3);
  addNode(&mainList, 2);
  addNode(&mainList, 1);
  printList(mainList);

  (isPalindromeV2(mainList)) ? printf("List is palindrome\n")
                             : printf("List is not palindrome\n");
  printf("\n");

  return EXIT_SUCCESS;
}
