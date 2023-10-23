#include <stdio.h>

int binarySearch(int arr[], int arrSize, int target)
{
    int l = 0;
    int h = arrSize - 1;

    while (l <= h)
    {
        int mid = l + ((h - l) / 2);

        if (arr[mid] == target)
            return mid;

        else if (target < arr[mid])
            h = mid - 1;

        else
            l = mid + 1;
    }

    return -1;
}

int main()
{
    int a[] = {1, 2, 3, 4, 5, 6, 7};
    int size = sizeof(a) / sizeof(a[0]);
    int k = 5;

    printf("Element: %d is located in %d", k, binarySearch(a, size, k));

    return 0;
}