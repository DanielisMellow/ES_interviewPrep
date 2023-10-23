#include <stdio.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void sortColors(int arr[], int size)
{
    int low = 0;
    int mid = 0;
    int high = size - 1;

    while (mid <= high)
    {
        switch (arr[mid])
        {
        case 0:
            swap(&arr[low++], &arr[mid++]);
            break;
        case 1:
            mid++;
            break;
        case 2:
            swap(&arr[high--], &arr[mid]);
            break;
        default:
            break;
        }
    }
}

void printArr(int arr[], int size)
{

    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main()
{
    int nums[] = {2, 0, 2, 1, 1, 0};

    int sizeNums = sizeof(nums) / sizeof(nums[0]);

    printArr(nums, sizeNums);
    sortColors(nums, sizeNums);
    printArr(nums, sizeNums);
}