#include <stdio.h>
#include <stdlib.h>

void printArr(int arr[], int size) {
  for (int i = 0; i < size; i++) {
    printf("%d\t", arr[i]);
  }

  printf("\n");
}

int *shuffleArr(int *nums, int numsSize, int n, int *returnSize) {

  *returnSize = numsSize;

  for (int i = 0; i < n; i++) {
    nums[i] = nums[i] << 10;
    nums[i] |= nums[i + n]; // Store X and Y values together
  }

  int j = numsSize - 1;
  for (int i = n - 1; i > -1; i--) {
    int y = nums[i] & (0b1111111111);
    int x = nums[i] >> 10;

    nums[j] = y;
    nums[j - 1] = x;

    j -= 2;
  }

  return nums;
}

int *shuffleArrV2(int *nums, int numsSize, int n, int *returnSize) {
  *returnSize = numsSize;
  int *results = (int *)malloc(numsSize * sizeof(int));

  int j = 0;
  for (int i = 0; i < n; i++) {

    results[j] = nums[i];
    results[j + 1] = nums[n + i];
    j += 2;
  }

  return results;
}

int main() {

  int Arr[] = {2, 5, 1, 3, 4, 7};
  int sizeArr = sizeof(Arr) / sizeof(Arr[0]);

  printArr(Arr, sizeArr);

  int *shuffle = NULL;
  int sizeShuffle = 0;
  int n = 3;

  shuffle = shuffleArrV2(Arr, sizeArr, n, &sizeShuffle);

  printArr(shuffle, sizeShuffle);

  return 0;
}
