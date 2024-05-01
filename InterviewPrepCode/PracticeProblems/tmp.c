#include <stdio.h>
#include <string.h>

int main() {
  char result[50] = {0};

  for (int i = 0; i < 10; i++) {
    sprintf(result, "HelloWord:%d \n", i);
    int len = strlen(result);
    printf("Size of Result str: %d\n", len);
    printf("%s\n", result);
  }

  return 0;
}
