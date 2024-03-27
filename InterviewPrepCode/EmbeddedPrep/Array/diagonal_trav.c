#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

int const MAX = 3;

void print_matrix_diagonal(int m[MAX][MAX], int size) {

  bool is_up = true;

  int i = 0;
  int j = 0;
  int k = 0;

  while (k < size * size) {
    if (is_up) {
      while (i >= 0 && j < size) {
        printf("%d ", m[i][j]);
        k++;
        j++;
        i--;
      }
      if (i < 0 && j <= size - 1) {
        i = 0;
      } else {
        i += 2;
        j--;
      }
    } else {
      while (j >= 0 && i < size) {
        printf("%d ", m[i][j]);
        k++;
        j--;
        i++;
      }
      if (j < 0 && i <= size - 1) {
        j = 0;
      } else {
        j += 2;
        i--;
      }
    }
    is_up = !is_up;
  }
}

int main(int argc, char *argv[]) {

  int Matrix[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};

  int n = 3;
  print_matrix_diagonal(Matrix, n);
  return EXIT_SUCCESS;
}
