#include <stdio.h>
#include <stdlib.h>

void print_arr(int *arr, int size) {

  printf("[");
  for (int i = 0; i < size - 1; i++) {
    printf("%d,", arr[i]);
  }
  printf("%d]\n", arr[size - 1]);
}

void practicing_typing(int iterations) {
  for (int i = 0; i < 10; i++) {
    printf("How did your interview go\n");
  }
}

int main(void) {

  int A[] = {0, 1, 2, 3, 4, 5, 6, 7};
  int size = sizeof(A) / sizeof(A[0]);
  print_arr(A, size);

  printf("Hello World!");
  return EXIT_SUCCESS;
}
