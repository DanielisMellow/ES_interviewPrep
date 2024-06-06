#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#define MAX_STACK_SIZE 10
#define MAX_STRING_SIZE 32

typedef struct {
  char data[MAX_STACK_SIZE][MAX_STRING_SIZE];
  int top;
} Stack;

void init_stack(Stack *stack) { stack->top = -1; }

bool is_empty(Stack *stack) { return stack->top == -1; }

bool is_full(Stack *stack) { return stack->top == MAX_STACK_SIZE - 1; }

void push(Stack *stack, char *str) {
  if (is_full(stack)) {
    printf("Stack is full\n.");
    return;
  }
  stack->top++;
  strcpy(stack->data[stack->top], str);
}

char *pop(Stack *stack) {
  static char to_return[32];
  if (is_empty(stack)) {
    printf("Stack is empty.\n");
    return "!!!!";
  }
  strcpy(to_return, stack->data[stack->top]);
  stack->top--;
  return to_return;
}

char *peek(Stack *stack) {
  if (is_empty(stack)) {
    printf("Stack is empty.\n");
    return "!!!!";
  }
  return stack->data[stack->top];
}

char *reverse_words_str(const char *phrase, int phrase_size) {

  Stack word_stack;
  init_stack(&word_stack);

  char word[32] = {0};

  int count = 0;
  for (int i = 0; i < phrase_size; i++) {
    if (phrase[i] != ' ') {
      word[count] = phrase[i];
      count++;
    } else {
      word[count] = '\0';
      push(&word_stack, word);
      count = 0;
    }
  }
  word[count] = '\0';
  push(&word_stack, word);

  static char to_return[64] = {0};
  while (!is_empty(&word_stack)) {
    strcat(to_return, pop(&word_stack));
    if (word_stack.top > -1) {
      strcat(to_return, " ");
    }
  }
  return to_return;
}

int main(void) {

  const char long_phrase[] = "The Sky is Blue";
  int phrase_size = sizeof(long_phrase) / sizeof(long_phrase[0]);
  printf("Original String:%s\n", long_phrase);
  char *reversed_str = reverse_words_str(long_phrase, phrase_size);
  printf("New String:%s\n", reversed_str);

  return 0;
}
