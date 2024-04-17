#include <stdio.h>
#include <stdlib.h>

void swap(char *a, char *b) {
  *a ^= *b;
  *b ^= *a;
  *a ^= *b;
}

void reverse(char arr[], int size) {

  int i = 0;
  int j = size - 2;
  while (i < j) {
    swap(&arr[i], &arr[j]);
    i++;
    j--;
  }
}

int main(int argc, char *argv[]) {
  char str[] = "HelloWorld!";
  int size = sizeof(str) / sizeof(str[0]);

  printf("%s\n%d\n\n", str, size);
  reverse(str, size);

  printf("%s\n%d\n\n", str, size);

  return EXIT_SUCCESS;
}
