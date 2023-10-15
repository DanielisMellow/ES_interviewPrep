#include <limits.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct Queue {
  int *capacity;
  int front, rear, size;

} queue;

queue *createQueue(unsigned int size) {
  queue *q = (queue *)malloc(sizeof(queue));

  if (q == NULL) {
    printf("Can't Allocate Space for Queue\n");
    return NULL;
  }

  q->capacity = (int *)malloc(sizeof(int) * size);

  if (q->capacity == NULL) {
    printf("Can't Allocate Space for Queue\n");
    return NULL;
    free(q);
  }

  q->front = 0;
  q->rear = 0;
  q->size = size;

  return q;
}

void enqueue(queue *q, int newItem) {
  if (q->rear == q->size) {
    printf("Queue is Full\n");
  } else {
    q->capacity[q->rear] = newItem;
    q->rear++;
  }
}

int dequeue(queue *q) {
  if (q->front == q->rear) {
    printf("Queue is Empty\n");
    return INT32_MIN;
  }
  int item = q->capacity[q->front];
  q->front++;
  if (q->front == q->rear) {
    q->front = 0;
    q->rear = 0;
  }
  return item;
}

void display_queue(queue *q) {
  if (q->front == q->rear) {
    printf("\nQueue is Empty unable to display\n");
    return;
  }
  for (int i = q->front; i < q->rear; i++) {
    printf("%d - ", q->capacity[i]);
  }
  printf("\n");
}

void freeQueue(queue *q) {
  free(q->capacity);
  free(q);
}

int main(int argc, char *argv[]) {
  queue *user_queue = NULL;

  user_queue = createQueue(8);
  for (int i = 0; i < 8; i++) {
    enqueue(user_queue, i);
  }
  display_queue(user_queue);

  for (int i = 0; i < 16; i++) {
    dequeue(user_queue);
  }
  display_queue(user_queue);

  for (int i = 0; i < 4; i++) {
    enqueue(user_queue, i);
  }
  display_queue(user_queue);

  freeQueue(user_queue);
  return EXIT_SUCCESS;
}
