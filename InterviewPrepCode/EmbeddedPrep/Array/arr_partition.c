#include <stdio.h>
#include <stdlib.h>

int cmpfunc(const void *a, const void *b) { return (*(int *)a - *(int *)b); }

int sum_of_partions(int a[], int size) {
  qsort(a, size, sizeof(int), cmpfunc);

  int sum = 0;
  for (int i = 0; i < size; i += 2) {
    sum += a[i];
  }
  return sum;
}
void print_arr(int a[], int size) {

  for (int i = 0; i < size; i++) {
    printf("%d ", a[i]);
  }
  printf("\n");
}

int main(int argc, char *argv[]) {
  int arr[] = {1, 4, 3, 2};
  int size = sizeof(arr) / sizeof(arr[0]);
  print_arr(arr, size);
  int sum = sum_of_partions(arr, size);
  printf("Sum of partition: %d\n", sum);
  return EXIT_SUCCESS;
}
