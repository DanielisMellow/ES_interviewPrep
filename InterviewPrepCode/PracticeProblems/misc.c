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

    printf("Hello World!\n");
  }
  printf("\n\n");
}

void wrapper_print(int *arr, int size) {

  for (int i = 0; i < size; i++) {

    practicing_typing(arr[i]);
  }
}
void print_triangle(int n) {

  for (int i = n; i > 1; i--) {
    for (int j = 0; j < n - i; j++) {
      printf("*");
    }
    printf("\n");
  }
}

void print_eq_triangle(int rows) {

  int i, j, space;
  for (i = rows; i >= 1; --i) {
    for (space = 0; space < rows - i; ++space)
      printf("  ");
    for (j = i; j <= 2 * i - 1; ++j)
      printf("* ");
    for (j = 0; j < i - 1; ++j)
      printf("* ");
    printf("\n");
  }
}

int main(void) {

  int A[] = {
      0, 1, 2, 3, 4, 5, 6, 7,
  };
  int size = sizeof(A) / sizeof(A[0]);
  print_arr(A, size);

  for (int i = size - 1; i >= 0; i--) {
    print_eq_triangle(A[i]);
  }

  return EXIT_SUCCESS;
}
