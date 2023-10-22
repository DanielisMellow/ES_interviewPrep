#include <stdio.h>

/// Swapping without temp variable
void swapV2(int *a, int *b)
{

    *a ^= *b;
    *b ^= *a;
    *a ^= *b;
}

void swap(int *a, int *b)
{
    int temp = *b;
    *b = *a;
    *a = temp;
}

void ReverseArr(int arr[], int size)
{
    size = size - 1; // A[7]     A[0] ---->A[6]
    for (int i = 0; i < size / 2; i++)
    {
        swap(&arr[i], &arr[size - i]);
    }
}

void printArr(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d\t", arr[i]);
    }

    printf("\n");
}

int main()
{
    int arr[] = {0, 1, 2, 3, 4, 5, 6};

    int size = sizeof(arr) / sizeof(arr[0]);

    printArr(arr, size);

    ReverseArr(arr, size);

    printArr(arr, size);

    return 0;
}

// 0       1       2       3       4       5       6
// 6       5       4       3       2       1       0