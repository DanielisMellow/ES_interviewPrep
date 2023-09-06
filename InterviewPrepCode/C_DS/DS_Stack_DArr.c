#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

struct Stack
{
    int top;
    int size;
    int *items;
};

typedef struct Stack stack;

void stack_init(stack *s, int size)
{
    s->items = (int *)malloc(sizeof(int) * size);
    s->size = size;
    s->top = -1;
}

int isEmpty(stack *s)
{
    return s->top == -1;
}

int isFull(stack *s)
{
    return s->top == s->size - 1;
}

int push(stack *s, int newItem)
{
    if (isFull(s))
    {
        printf("Stack Is Full\n");
        return INT32_MIN;
    }
    else
    {
        s->top += 1;
        s->items[s->top] = newItem;
        return newItem;
    }
}

int pop(stack *s)
{
    if (isEmpty(s))
    {
        printf("Stack Is Empty\n");
        return INT32_MIN;
    }
    int temp = s->items[s->top];
    s->top--;
    return temp;
}

int peek(stack s, int pos)
{
    if (pos >= s.size || pos < 0)
        return INT32_MIN;

    else
    {
        int temp = s.items[s.top - pos];

        return temp;
    }
}

int main()
{
    stack S;

    stack_init(&S, 5);

    for (int i = 0; i < 10; i++)
    {
        push(&S, i) != INT32_MIN ? printf("Pushed: %d\n", i) : printf("");
    }

    // for (int i = 0; i < 10; i++)
    // {
    //     int item = pop(&S);
    //     item != INT32_MIN ? printf("Popped: %d out of the stack\n", item) : printf("");
    // }

    int item3 = peek(S, 3);
    printf("\n\n %d \n", item3);

    return 0;
}