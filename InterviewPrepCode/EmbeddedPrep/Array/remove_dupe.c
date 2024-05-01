
#include <stdio.h>
#include <stdlib.h>

int remove_dupes(int arr[], int size) {

  int j = 0;
  for (int i = 0; i < size - 1; i++) {

    while (arr[i] == arr[j]) {
      if (j == size - 1) {
        break;
      }
      j++;
      if (arr[i] != arr[j]) {
        arr[i + 1] = arr[j];
      }
    }
  }

  int new_size = 0;
  while (arr[new_size] < arr[new_size + 1]) {
    new_size++;
  }
  return new_size + 1;
}

int remove_dupesV2(int arr[], int size) {
  // The first element is always unique
  int pos = 1;
  for (int i = 1; i < size; i++) {
    // if the current element is greater prev
    // then update value pointed by position idx pointer
    if (arr[i] > arr[i - 1]) {
      arr[pos] = arr[i];
      pos++;
    }
  }
  return pos;
}

void print_arr(int arr[], int size) {
  for (int i = 0; i < size; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");
}
int main(int argc, char *argv[]) {

  int main_arr[] = {1, 1, 2, 3, 3, 3, 4, 4};
  int size = sizeof(main_arr) / sizeof(main_arr[0]);

  print_arr(main_arr, size);

  int new_size = remove_dupesV2(main_arr, size);

  print_arr(main_arr, size);
  return EXIT_SUCCESS;
}
