#include <stdio.h>
#include <stdlib.h>

#define BUFFER_SIZE 10
#define SUCCESS 0
#define BUFFER_FULL -1
#define BUFFER_EMPTY -1

typedef struct
{
    int buffer[BUFFER_SIZE];
    int head;
    int tail;
    int isFull;
} CircularBuffer;

void initialize_buffer(CircularBuffer *cb)
{
    cb->head = 0;
    cb->tail = 0;
    cb->isFull = 0;
}

int isFull(CircularBuffer *cb)
{
    return cb->isFull;
}

int insert(CircularBuffer *cb, int elem)
{
    if (isFull(cb))
    {
        return BUFFER_FULL;
    }

    cb->buffer[cb->tail] = elem;
    cb->tail = (cb->tail + 1) % BUFFER_SIZE;

    if (cb->tail == cb->head)
        cb->isFull = 1;

    return SUCCESS;
}

int remove_elem(CircularBuffer *cb, int *elem)
{
    if (cb->head == cb->tail && !cb->isFull)
    {
        return -1; // Buffer is Empty
    }

    *elem = cb->buffer[cb->head];
    cb->head = (cb->head + 1) % BUFFER_SIZE;
    cb->isFull = 0;

    return SUCCESS;
}

int main()
{
    CircularBuffer cb;
    initialize_buffer(&cb);
    // Test the circular buffer
    for (int i = 0; i < 15; i++)
    {
        if (insert(&cb, i * 2) == BUFFER_FULL)
        {
            printf("Buffer is full. Can't insert %d\n", i * 2);
        }
        else
        {
            printf("Inserted %d into buffer\n", i * 2);
        }
    }

    printf("=============================================================\n");

    for (int i = 0; i < 20; i++)
    {
        int data;
        if (remove_elem(&cb, &data) == BUFFER_FULL)
        {
            printf("Buffer is empty. Can't remove data.\n");
        }
        else
        {
            printf("Removed %d from buffer\n", data);
        }
    }

    return 0;
}