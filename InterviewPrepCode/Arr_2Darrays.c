#include <stdio.h>
#include <stdlib.h>

void print2Darr(int *arr, int rowSize, int columnSize)
{
    for (int i = 0; i < rowSize; i++)
    {
        for (int j = 0; j < columnSize; j++)
        {
            printf("%d ", *(arr + i * columnSize + j));
            // printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

int main()
{

    // 2D array stored in Stack
    int A[3][3] = {{1, 2, 3}, {3, 2, 1}, {1, 2, 3}};

    printf("2D array Stored in the Stack: \n");
    print2Darr(A[0], 3, 3);

    // 2D Array created by an array of pointers (stack) pointing to arrays (heap)
    int *B[3];
    B[0] = (int *)malloc(3 * sizeof(int));
    B[1] = (int *)malloc(3 * sizeof(int));
    B[2] = (int *)malloc(3 * sizeof(int));

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
            B[i][j] = j;
    }

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
            printf("%d ", B[i][j]);
        printf("\n");
    }
    printf("\n");

    for (int i = 0; i < 3; i++)
    {
        free(B[i]);
    }

    // 2D array created by a double pointer(stack)  points to an array of pointers(heap) which point to arrays(heap)
    int **C = (int **)malloc(3 * sizeof(int *));

    C[0] = (int *)malloc(3 * sizeof(int));
    C[1] = (int *)malloc(3 * sizeof(int));
    C[2] = (int *)malloc(3 * sizeof(int));

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
            C[i][j] = i;
    }
    printf("2D array Stored in the Heap: \n");
    // Access Elements using nested for loops
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
            printf("%d ", C[i][j]);
        printf("\n");
    }
    printf("\n");

    // Don't forget to free the memory when done
    for (int i = 0; i < 3; i++)
    {
        free(C[i]);
    }
    free(C);

    return 0;
}