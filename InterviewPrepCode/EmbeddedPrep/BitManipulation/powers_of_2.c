#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

uint32_t powers_of_two(uint8_t exponent) {
  uint32_t result = 0;
  result |= 1 << exponent;
  return result;
}

int main(int argc, char *argv[]) {
  uint32_t power = 0;
  for (int i = 0; i < 32; i++) {
    power = powers_of_two(i);
    printf("%u\n", power);
    printf("%032b\n", power);
  }

  return EXIT_SUCCESS;
}
