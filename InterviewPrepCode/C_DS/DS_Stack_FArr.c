#include <stdint.h>
#include <stdio.h>

// Hello from sal in neo vim
#define MAX_SIZE 10

typedef struct {
  int items[MAX_SIZE];
  int top;
} Stack;

void initialize(Stack *s) { s->top = -1; }

int isEmpty(Stack *s) { return s->top == -1; }

int isFull(Stack *s) { return s->top == MAX_SIZE - 1; }

void push(Stack *s, int newItem) {
  if (isFull(s))
    printf("STACK FULL. PUSH FAILED\n");

  else {
    s->top += 1;
    s->items[s->top] = newItem;
  }
}

int pop(Stack *s) {
  if (isEmpty(s)) {
    printf("STACK EMPTY. POP FAILED\n");
    return -1;
  }

  int item = s->items[s->top];
  s->top--;

  return item;
}

int main() {

  Stack s;
  initialize(&s);

  for (int i = 0; i < 16; i++) {
    int item = i * 8;
    printf("Attempting to Push: %d into stack\n", item);
    push(&s, item);
  }

  for (int i = 0; i < 10; i++) {
    int item = pop(&s);
    if (item != -1)
      printf("%d was Popped from Stack\n", item);
  }
}
