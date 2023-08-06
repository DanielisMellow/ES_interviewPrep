#include <stdio.h>

void printMissingNumbers(int A[], int size)
{
    int diff = A[0];

    for (int i = 0; i < size; i++)
    {
        if ((A[i] - i) != diff)
        {
            while (diff < A[i] - i)
            {
                printf("%d\n", i + diff);
                diff++;
            }
        }
    }
}

int main()
{

    int arr[] = {6, 7, 8, 9, 11, 12, 19};

    int sizeArr = sizeof(arr) / sizeof(arr[0]);

    printMissingNumbers(arr, sizeArr);

    return 0;
}