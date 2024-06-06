#include <stdio.h>
#include <stdlib.h>

// Given an integer n, return an array ans of length n + 1
// such that for each i (0 <= i <= n),
// ans[i] is the number of 1's in the binary representation of i.

int *countBits(int num, int *returnSize) {
  int i = 0, k = 4, ano = 4;
  int num1 = num;
  *returnSize = (num + 1);
  int *arr = malloc(sizeof(int) * (num + 1));

  if (num1 > 3)
    num1 = 3;
  switch (num1) {
  case 3:
    arr[3] = 2;
    num--;
    num1--;
  case 2:
    arr[2] = 1;
    num--;
    num1--;
  case 1:
    arr[1] = 1;
    num--;
    num1--;
  case 0:
    arr[0] = 0;
    num--;
    break;
  }

  while (num >= 0) {
    if (i >= ano) {
      ano *= 2;
      i = 0;
    }
    arr[k] = arr[i % ano] + 1;
    i++;
    k++;
    num--;
  }
  return arr;
}

int main() {
  int x = 5;

  int *p = NULL;
  int size = 0;

  p = countBits(x, &size);

  for (int i = 0; i < size; i++) {
    printf("%d\n", p[i]);
  }

  free(p);
}
