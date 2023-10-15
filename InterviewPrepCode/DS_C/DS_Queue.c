#include <stdio.h>

#define MAX_SIZE 8

typedef struct {
  int items[MAX_SIZE];
  int front;
  int rear;
} Queue;

void initialize(Queue *q) {
  q->front = 0;
  q->rear = 0;
}

void enqueue(Queue *q, int newItem) {
  if (q->rear == MAX_SIZE)
    printf("QUEUE IS FULL\n");
  else {
    q->items[q->rear] = newItem;
    q->rear++;
  }
}

int dequeue(Queue *q) {
  if (q->front == q->rear) {
    printf("QUEUE IS EMPTY\n");
    return -1;
  } else {
    int item = q->items[q->front];
    q->front++;
    if (q->front == q->rear) {
      q->front = 0;
      q->rear = 0;
    }
    return item;
  }
}

int main() {
  Queue q;
  initialize(&q);
  for (int i = 0; i < 16; i++) {
    printf("Attempting to enqueue: %d\n", i);
    enqueue(&q, i);
  }

  for (int i = 0; i < 16; i++) {

    printf("Dequeued: %d\n", dequeue(&q));
  }

  return 0;
}
