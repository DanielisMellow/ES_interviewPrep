#include <stdio.h>
#include <stdlib.h>

int linearSearch(int A[], int key, int size) {
  for (int i = 0; i < size; i++) {

    if (A[i] == key) {

      return i;
    }
  }

  return -1;
}

int main(int argc, char *argv[]) {

  int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
  int size = sizeof(arr) / sizeof(arr[0]);
  int key = 7;

  if (linearSearch(arr, key, size) != -1) {
    printf("Key %d is located in idx: %d\n", key, linearSearch(arr, key, size));
  } else {
    printf("Key is not located in arr\n");
  }

  return EXIT_SUCCESS;
}
