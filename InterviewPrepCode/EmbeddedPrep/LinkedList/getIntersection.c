#include "LinkedList.h"
#include <stdio.h>

// Solution 1: Brute force
node *getIntersectionNodeV1(node *head1, node *head2) {
  while (head2 != NULL) {
    node *temp = head1;
    while (temp != NULL) {
      if (temp == head2) {
        return head2;
      }
      temp = temp->next;
    }
    head2 = head2->next;
  }
  return NULL;
}
// Soulution 2: Using Difference in node counts

/* Function to get the counts of node in a linked list */
int getCount(node *head);

/* function to get the intersection point of two linked
   lists head1 and head2 where head1 has d more nodes than
   head2 */
node *_getIntesectionNode(int d, node *head1, node *head2);

/* function to get the intersection point of two linked
   lists head1 and head2 */
node *getIntesectionNode(node *head1, node *head2) {
  int c1 = getCount(head1);
  int c2 = getCount(head2);
  int d;

  if (c1 > c2) {
    d = c1 - c2;
    return _getIntesectionNode(d, head1, head2);
  } else {
    d = c2 - c1;
    return _getIntesectionNode(d, head2, head1);
  }
}

/* function to get the intersection point of two linked
   lists head1 and head2 where head1 has d more nodes than
   head2 */
node *_getIntesectionNode(int d, node *head1, node *head2) {
  int i;
  node *current1 = head1;
  node *current2 = head2;

  for (i = 0; i < d; i++) {
    if (current1 == NULL) {
      return NULL;
    }
    current1 = current1->next;
  }

  while (current1 != NULL && current2 != NULL) {
    if (current1 == current2)
      return current1;
    current1 = current1->next;
    current2 = current2->next;
  }

  return NULL;
}

/* Takes head pointer of the linked list and
   returns the count of nodes in the list */
int getCount(node *head) {
  node *current = head;
  int count = 0;

  while (current != NULL) {
    count++;
    current = current->next;
  }

  return count;
}

// Soulution 3: Two pointer technique
node *intersectionNode(node *head1, node *head2) {
  node *temp1 = head1;
  node *temp2 = head2;

  if (temp1 == NULL || temp2 == NULL) {
    return NULL;
  }

  while (temp1 != temp2) {

    temp1 = temp1->next;
    temp2 = temp2->next;

    if (temp1 == temp2) {
      return temp1;
    }

    if (temp1 == NULL) {
      temp1 = head2;
    }

    if (temp2 == NULL) {
      temp2 = head1;
    }
  }
  return temp1;
}
