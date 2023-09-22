#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

struct Queue {
  int *arr;
  int front;
  int rear;
  int capacity;
};

typedef struct Queue queue;

void createQueue(queue *cq, int capacity) {
  cq->arr = (int *)malloc(sizeof(int) * capacity);
  if (cq->arr == NULL) {
    printf("Unable to Allocate Memmory for Queue\n");
    return;
  }

  cq->front = cq->rear = -1;
  cq->capacity = capacity;
}

int isFull(queue *cq) { return ((cq->rear + 1) % cq->capacity == cq->front); }

int isEmpty(queue *cq) { return cq->front == -1; }

void enqueue(queue *cq, int item) {
  if (isFull(cq)) {
    printf(("Queue is Full\n"));
    return;
  }
  if (isEmpty(cq)) {
    cq->front = cq->rear = 0;
  } else {
    cq->rear = (cq->rear + 1) % cq->capacity;
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
    cq->front = (cq->front + 1) % cq->capacity;
  }
  return data;
}

int main() {
  queue circularQueue;
  createQueue(&circularQueue, 3);
  int verbose = 1;

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
    (data != INT_MIN) ? printf("Dequeued: %d\n", data) : printf("\n");
    if (verbose) {
      printf("Front: %d\t Rear: %d\n\n", circularQueue.front,
             circularQueue.rear);
    }
  }

  return 0;
}
