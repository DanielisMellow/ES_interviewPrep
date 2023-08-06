#include <stdio.h>

int search(int *nums, int numsSize, int target)
{
    int l = 0;
    int r = numsSize - 1;

    while (l <= r)
    {
        int mid = (l + r) / 2;
        if (target == nums[mid])
            return mid;

        // left sorted portion
        if (nums[l] <= nums[mid])
        {
            if (target > nums[mid] || target < nums[l])
                l = mid + 1;
            else
            {
                r = mid - 1;
            }
        }
        // Right Sorted Portion
        else
        {
            if (target < nums[mid] || target > nums[r])
            {
                r = mid - 1;
            }
            else
            {
                l = mid + 1;
            }
        }
    }

    return -1;
}

int main()
{

    int a[] = {4, 5, 6, 7, 0, 1, 2};
    int size = sizeof(a) / sizeof(a[0]);

    int n = 1;
    printf("%d is located at index: %d\n", n, search(a, size, n));

    return 0;
}