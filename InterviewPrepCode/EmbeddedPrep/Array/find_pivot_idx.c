#include <stdio.h>

int fid_pivot_idx(int *arr, int size) {

  int pivot = size / 2;
  while (pivot >= 0 && pivot < size) {
    int left_sum = 0;
    int right_sum = 0;

    for (int i = 0; i < pivot; i++) {

      left_sum += arr[i];
    }

    for (int j = pivot + 1; j < size; j++) {
      right_sum += arr[j];
    }

    if (left_sum == right_sum) {
      return pivot;
    }

    (left_sum < right_sum) ? pivot++ : pivot--;
  }

  return pivot;
}

int find_pivot_idx(int *arr, int size) {

  int total = 0;
  int left_sum = 0;
  for (int i = 0; i < size; i++) {
    total += arr[i];
  }
  for (int j = 0; j < size; j++) {

    int right_sum = total - arr[j] - left_sum;

    if (left_sum == right_sum) {
      return j;
    }

    left_sum += arr[j];
  }

  return -1;
}

int main(int argc, char *argv[]) {

  int A[] = {1, 7, 3, 6, 5, 6};
  // int A[] = {2, -1, -1};
  size_t len = sizeof(A) / sizeof(A[0]);

  for (int i = 0; i < len; i++) {
    printf("%d ", A[i]);
  }
  printf("\n");

  printf("Pivot idx:%d", fid_pivot_idx(A, len));

  return 0;
}
