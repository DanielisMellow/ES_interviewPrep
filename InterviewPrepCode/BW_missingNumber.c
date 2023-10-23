#include <stdio.h>

int missingNumber(int *nums, int numsSize)
{
    // For xor of all the elements in array
    int x1 = 0;
    // For xor of all the elements from 1 to n+1
    int x2 = 0;

    for (int i = 0; i < numsSize; i++)
        x1 = x1 ^ nums[i];

    for (int i = 0; i < numsSize + 1; i++)
        x2 = x2 ^ i;

    printf("%d\n", x1);
    printf("%d\n", x2);

    return (x1 ^ x2);
}

// Function to find the missing number
int getMissingNo(int a[], int n)
{
    int i, total;
    total = (n * (n + 1)) / 2;
    for (i = 0; i < n; i++)
        total -= a[i];
    return total;
}

int main()
{

    int A[] = {9, 6, 4, 2, 3, 5, 7, 0, 1};

    // int A[] = {0, 1};
    int size = sizeof(A) / sizeof(A[0]);

    int miss = missingNumber(A, size);
    printf("The missing number is: %d\n", miss);

    printf("The missing number is: %d\n", getMissingNo(A, size));
}