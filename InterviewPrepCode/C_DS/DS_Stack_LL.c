#include <limits.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

struct Node {
  int data;
  struct Node *next;
};

typedef struct Node node;

struct Stack {
  node *top;
};

typedef struct Stack stack;

node *create_node(int data) {
  node *newNode = (node *)malloc(sizeof(node));
  if (newNode == NULL) {
    printf("Unable To Allocate space for a new Node");
    exit(EXIT_FAILURE);
  }
  newNode->data = data;
  newNode->next = NULL;

  return newNode;
}

/* Initialize the stack */
void initStack(stack *s) { s->top = NULL; }

int isEmpty(stack *s) { return s->top == NULL; }

/* Push item onto stack */
void push(stack *s, int data) {
  node *newNode = create_node(data);
  newNode->next = s->top;
  s->top = newNode;
}

/* Pop item from stack */
int pop(stack *s) {
  if (isEmpty(s)) {
    printf("Error: Stack underflow.\n");
    return INT32_MIN;
  }

  node *temp = s->top;
  int poppedData = temp->data;
  s->top = temp->next;
  free(temp);
  return poppedData;
}

/* Peek at the top itep from the stack  */
int peek(stack *s) {
  if (isEmpty(s)) {
    printf("Error:Stack is Empty\n");
    return INT32_MIN;
  }
  return s->top->data;
}

/* Clean up and free memory of stack */
void freeStack(stack *s) {
  while (!isEmpty(s)) {
    pop(s);
  }
}

int main(int argc, char *argv[]) {
  stack st;
  initStack(&st);

  for (int i = 0; i < 5; i++) {
    push(&st, i);
  }
  printf("Top Element: %d\n", peek(&st));

  return 0;
}
