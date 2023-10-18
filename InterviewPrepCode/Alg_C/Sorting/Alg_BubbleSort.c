#include <stdio.h>
#include <stdlib.h>

// Function to swap two elements
void swap(int *a, int *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}

// Adding a flag makes bubbleSort as adaptive
void bubbleSort(int A[], int size) {

  // Iterate through some passes
  for (int i = 0; i < size - 1; i++) {
    int flag = 0;

    for (int j = 0; j < size - i - 1; j++) {
      if (A[j] > A[j + 1]) {
        swap(&A[j], &A[j + 1]);
        flag = 1;
      }
    }
    // If no two elemenets were swapped by inner loop, then break
    if (flag == 0) {
      break;
    }
  }
}

int main() {
  int A[] = {7, 2, 1, 6, 8, 5, 3, 4};
  int size = sizeof(A) / sizeof(A[0]);

  for (int i = 0; i < size; i++)
    printf("%d ", A[i]);

  printf("\n");

  bubbleSort(A, size);

  for (int i = 0; i < size; i++)
    printf("%d ", A[i]);

  printf("\n");
  return 0;
}
