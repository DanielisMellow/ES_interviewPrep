#include <limits.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

struct Node {
  int data;
  struct Node *next;
};

typedef struct Node node;

typedef struct Queue {
  node *front;
  node *rear;
} queue;

node *createNode(int data) {
  node *newNode = (node *)malloc(sizeof(node));
  if (newNode == NULL) {
    printf("Unable to Allocate Space");
    return NULL;
  }
  newNode->data = data;
  newNode->next = NULL;

  return newNode;
}

void createQueue(queue *q) {
  q->rear = NULL;
  q->front = NULL;
}

int isEmpty(queue *q) { return q->front == NULL; }

void enqueue(queue *q, int data) {
  node *newNode = createNode(data);

  if (q->rear == NULL) {
    q->front = newNode;
    q->rear = newNode;
    return;
  }

  q->rear->next = newNode;
  q->rear = newNode;
}

int dequeue(queue *q) {

  if (isEmpty(q)) {
    printf("Queue is Empty\n");
    return INT32_MIN;
  }

  node *temp = q->front;
  int data = temp->data;

  q->front = q->front->next;

  if (q->front == NULL) {
    q->rear = NULL;
  }

  free(temp);
  return data;
}

int peek(queue q) {
  if (q.front == NULL) {
    printf("Queue is Empty\n");
    return INT32_MIN;
  }

  return q.front->data;
}

int main(int argc, char *argv[]) {
  queue userQueue;
  createQueue(&userQueue);

  for (int i = 0; i < 8; i++) {
    enqueue(&userQueue, i * 2);
  }

  printf("The Front of the Queue %d\n", peek(userQueue));
  for (int i = 0; i < 16; i++) {
    int data = dequeue(&userQueue);
    (data != INT32_MIN) ? printf("Dequeued: %d\n", data) : printf("");
  }

  return EXIT_SUCCESS;
}
