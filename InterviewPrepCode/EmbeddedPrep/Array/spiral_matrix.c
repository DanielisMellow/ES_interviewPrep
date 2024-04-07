#include <stdio.h>
#include <stdlib.h>

int const ROW = 3;
int const COL = 3;

void spiral_print(int m[ROW][COL]) {

  int left_bound = 0;
  int right_bound = COL;
  int top_bound = 0;
  int bottom_bound = ROW;

  while (left_bound < right_bound && top_bound < bottom_bound) {
    // left -> right
    for (int i = left_bound; i < right_bound; i++) {
      printf("%d,", m[top_bound][i]);
    }
    top_bound++;
    // right column
    for (int i = top_bound; i < bottom_bound; i++) {
      printf("%d,", m[i][right_bound - 1]);
    }
    right_bound--;

    if (!(left_bound < right_bound && top_bound < bottom_bound))
      break;

    // right -> left
    for (int i = right_bound - 1; i > left_bound - 1; i--) {
      printf("%d,", m[bottom_bound - 1][i]);
    }
    bottom_bound--;
    // left column
    for (int i = bottom_bound - 1; i > top_bound - 1; i--) {
      printf("%d,", m[i][left_bound]);
    }
    left_bound++;
  }
}

int main(int argc, char *argv[]) {

  int Matrix[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};

  spiral_print(Matrix);

  int n = 3;
  return EXIT_SUCCESS;
}
