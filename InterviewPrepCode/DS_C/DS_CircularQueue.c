#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

static int verbose = 1;
struct Queue {
  int *arr;
  int front;
  int rear;
  int size;
};

typedef struct Queue queue;

void createQueue(queue *cq, int size) {
  cq->arr = (int *)malloc(sizeof(int) * size);
  if (cq->arr == NULL) {
    printf("Unable to Allocate Memmory for Queue\n");
    return;
  }

  cq->front = cq->rear = -1;
  cq->size = size;
}

int isFull(queue *cq) { return ((cq->rear + 1) % cq->size == cq->front); }

int isEmpty(queue *cq) { return cq->front == -1; }

void enqueue(queue *cq, int item) {
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

int dequeue(queue *cq) {
  if (isEmpty(cq)) {
    printf("Queue is Empty\n");
    return INT_MIN;
  }
  int data = cq->arr[cq->front];

  // Check if Queue has only 1 item
  if (cq->front == cq->rear) {
    cq->front = cq->rear = -1;
  } else {
    cq->front = (cq->front + 1) % cq->size;
  }
  return data;
}

int main() {
  queue circularQueue;
  createQueue(&circularQueue, 3);

  for (int i = 0; i < 4; i++) {
    printf("Attempting to enqueue: %d\n", i);
    enqueue(&circularQueue, i);
    if (verbose) {
      printf("Front: %d\t Rear: %d\n\n", circularQueue.front,
             circularQueue.rear);
    }
  }

  printf("========================================\n");

  for (int i = 0; i < 4; i++) {
    int data = dequeue(&circularQueue);
    (data != INT_MIN) ? printf("Dequeued: %d\n", data) : printf("");
    if (verbose) {
      printf("Front: %d\t Rear: %d\n\n", circularQueue.front,
             circularQueue.rear);
    }
  }

  return 0;
}
