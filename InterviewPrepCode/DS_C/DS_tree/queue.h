#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

struct Node {
  struct Node *right;
  int data;
  struct Node *left;
};
typedef struct Node node;

struct Queue {
  node **arr;
  int front;
  int rear;
  int size;
};

typedef struct Queue queue;

void createQueue(queue *cq, int size);
int isFull(queue *cq);
int isEmpty(queue *cq);
void enqueue(queue *cq, node *item);
node *dequeue(queue *cq);
void freeQueue(queue *q);
