#include <math.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

float Q_rsqrt(float number) {
  int32_t i;
  float x2, y;
  const float threehalfs = 1.5F;
  x2 = number * 0.5;

  y = number;
  i = *(int32_t *)&y;        // Evil Floating point bit level hacking
  i = 0x5f3759df - (i >> 1); // what the fuck
  y = *(float *)&i;
  // 1st iteration newton method
  y = y * (threehalfs - (x2 * y * y));
  // 2nd iteration can be remove can be removed
  // y = y *(threehalfs - (x2 *y *y));

  return y;
}

float rsqrt(float number) { return 1 / sqrt(number); }

int main(int argc, char *argv[]) {

  for (int i = 1; i < 10; i++) {

    printf("Q_rsqrt: %f", Q_rsqrt(i));
    printf("\trsqrt: %f\n", rsqrt(i));
  }
  printf("size of int: %lu\n", sizeof(int));
  printf("size of long: %lu\n", sizeof(long));
  printf("size of float: %lu\n", sizeof(float));
  return EXIT_SUCCESS;
}
