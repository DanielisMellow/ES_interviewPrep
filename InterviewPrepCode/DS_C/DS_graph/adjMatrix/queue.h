#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

struct Queue {
  int *arr;
  int front;
  int rear;
  int size;
};

typedef struct Queue queue;

void createQueue(queue *cq, int size);
int isFull(queue *cq);
int isEmpty(queue *cq);
void enqueue(queue *cq, int item);
int dequeue(queue *cq);
void freeQueue(queue *q);
