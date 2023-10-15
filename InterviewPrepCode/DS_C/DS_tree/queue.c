#include "queue.h"

void createQueue(queue *cq, int size) {
  cq->arr = (node **)malloc(sizeof(node *) * size);
  if (cq->arr == NULL) {
    printf("Unable to Allocate Memmory for Queue\n");
    return;
  }

  cq->front = cq->rear = -1;
  cq->size = size;
}

int isFull(queue *cq) { return ((cq->rear + 1) % cq->size == cq->front); }

int isEmpty(queue *cq) { return cq->front == -1; }

void enqueue(queue *cq, node *item) {
  if (isFull(cq)) {
    printf(("Queue is Full\n"));
    return;
  }
  if (isEmpty(cq)) {
    cq->front = cq->rear = 0;
  } else {
    cq->rear = (cq->rear + 1) % cq->size;
  }
  cq->arr[cq->rear] = item;
}

node *dequeue(queue *cq) {
  if (isEmpty(cq)) {
    printf("Queue is Empty\n");
    return NULL;
  }
  node *data = cq->arr[cq->front];

  // Check if Queue has only 1 item
  if (cq->front == cq->rear) {
    cq->front = cq->rear = -1;
  } else {
    cq->front = (cq->front + 1) % cq->size;
  }
  return data;
}

void freeQueue(queue *q) { free(q->arr); }
