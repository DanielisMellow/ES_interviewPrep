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

void print_matrix_diagonalV1(int m[MAX][MAX], int size) {
  int rows = size, cols = size;
  int cur_row = 0, cur_col = 0;
  bool is_up = true;
  int counter = 0;

  while (counter != rows * cols) {
    if (is_up) {
      while (cur_row >= 0 && cur_col < cols) {
        printf("%d ", m[cur_row][cur_col]);
        counter++;
        cur_row--;
        cur_col++;
      }
      if (cur_col == cols) {
        cur_col--;
        cur_row += 2;
      } else {
        cur_row++;
      }
    } else {
      while (cur_row < size && cur_col >= 0) {

        printf("%d ", m[cur_row][cur_col]);

        counter++;
        cur_row++;
        cur_col--;
      }
      if (cur_row == rows) {
        cur_col += 2;
        cur_row--;
      } else {
        cur_col++;
      }
    }
    is_up = !is_up;
  }
}

int main(int argc, char *argv[]) {

  int Matrix[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};

  int n = 3;
  print_matrix_diagonal(Matrix, n);
  printf("\n");
  print_matrix_diagonalV1(Matrix, n);
  return EXIT_SUCCESS;
}
