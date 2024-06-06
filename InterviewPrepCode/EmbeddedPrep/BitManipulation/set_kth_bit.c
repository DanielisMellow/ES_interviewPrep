#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#define MASK(x) (unsigned char)(1 << (x))
#define BIT_SET(variable, x) variable |= (1 << x)
#define BIT_CLEAR(variable, x) variable &= ~(1 << x)
#define BIT_TOGGLE(variable, x) variable ^= (1 << x)
uint32_t set_bit(uint32_t *field, uint32_t k_bit) {

  *field |= 1 << k_bit;

  return *field;
}

int main(int argc, char *argv[]) {

  uint32_t mask = 0;

  printf("Mask in Binary: %032b\n", mask);
  printf("Mask in Hex: %08x\n", mask);
  int size = sizeof(mask) * 8;
  printf("%d\n", size);
  printf("===========\n");
  for (int i = 0; i < size; i++) {
    set_bit(&mask, i);
    printf("Mask in Binary: %032b\n", mask);
    printf("Mask in Hex: %08x\n", mask);
  }

  return EXIT_SUCCESS;
}
