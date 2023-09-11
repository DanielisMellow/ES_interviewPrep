#include <stdio.h>

#define SECONDS_PER_YEAR (60UL * 60UL * 24UL * 365UL)
#define MIN(A, B) ((A) <= (B) ? (A) : (B))

#define SET_BIT(x, pos) x |= (1 << pos)

// Fix this piece of code
int square(volatile int *ptr) { return *ptr * *ptr; }

// The Compiler will generate code that is something like this
// Since it is possible for the value of *ptr to change unexpectedly, it is
// possible for a and b to be different. The code could return a number that is
// not a square!

int square_Demo(volatile int *ptr) {
  int a, b;
  a = *ptr;
  b = *ptr;
  return a * b;
}

// This is how you fix the code
long square_Fix(volatile int *ptr) {
  int a;
  a = *ptr;
  return a * a;
}

int setbit3(int n) {
  n |= (0x01 << 3);
  return n;
}

int clearBit3(int n) {
  n &= ~(0x01 << 3);

  return n;
}

int main() {

  int *p = NULL;
  int x[] = {10, 20};
  int y = 30;
  p = x;

  printf("There are this many seconds in a year: %lu\n", SECONDS_PER_YEAR);

  // printf("%d\n", *p++);

  printf("Min: %d\n", MIN(*p++, y));

  printf("%d", setbit3(3));
}
