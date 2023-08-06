#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int *A;
    int size;
    int length;
} Array;

void Array_init(Array *arr, int size)
{
    arr->A = (int *)malloc(sizeof(int) * size);
    arr->size = size;
    arr->length = -1;
}

int isFull(Array *arr)
{
    return arr->length == arr->size - 1;
}

int isEmpty(Array *arr)
{
    return arr->length == -1;
}

void Array_display(Array *arr)
{
    printf("{ ");
    for (int i = 0; i <= arr->length; i++)
    {
        printf("%d ", arr->A[i]);
    }
    printf("}\n");
}

int Array_append(Array *arr, int element)
{
    if (!isFull(arr))
    {
        arr->length++;
        arr->A[arr->length] = element;

        return 1;
    }

    return 0;
}

int Array_remove(Array *arr)
{
    if (!isEmpty(arr))
    {
        int item = arr->A[arr->length];
        arr->length--;
        return item;
    }
    return INT_MIN;
}

void Array_insert(Array *arr, int item, int index)
{
    if (arr->length >= index && index > -1 && !isFull(arr))
    {
        for (int i = arr->length + 1; i > index; i--)
        {
            arr->A[i] = arr->A[i - 1];
        }
        arr->A[index] = item;
        arr->length++;
    }
}

int main()
{
    Array arr;
    int size = 0;

    while (size < 1)
    {
        printf("Enter size of an array: ");
        scanf("%d", &size);
    }
    Array_init(&arr, size);

    for (int i = 0; i < 30; i += 2)
    {
        (isFull(&arr)) ? printf("Is Full\n") : printf("Not Full\n");
        Array_append(&arr, i);
    }
    Array_display(&arr);

    for (int i = 0; i < 2; i++)
    {
        printf("Item %d was removed\n", Array_remove(&arr));
    }

    Array_display(&arr);

    Array_insert(&arr, 69, 7);

    Array_display(&arr);
    return 0;
}