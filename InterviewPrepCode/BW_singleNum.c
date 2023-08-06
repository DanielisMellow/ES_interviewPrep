#include <stdio.h>

int singleNumber(int *nums, int numsSize)
{
    int res = 0;
    for (int i = 0; i < numsSize; i++)
    {
        res ^= nums[i];
    }

    return res;
}

int main()
{
    int nums[] = {4, 1, 2, 1, 2};

    int size = sizeof(nums) / sizeof(nums[0]);

    // printf("%d\n", size);

    printf("The Single Number in the array is: %d\n", singleNumber(nums, size));

    return 0;
}
