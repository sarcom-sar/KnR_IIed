#include <stdio.h>
#include "2-07func.h"

int main(void) {
  unsigned int x = 255; // b11111111
  int p = 3; // 4th
  int n = 3; // flip 3 bits to 000
  printf("X = %u, p = %d, n = %d\n", x, p, n);
  // 241 == b11110001
  printf("X value: %u, expected value: %u\n", invert(x, p, n), 241);

  /* --- */

  x = 10; // b1010
  p = 3; // 4th
  n = 3;
  printf("X = %u, p = %d, n = %d\n", x, p, n);
  // 4 == b0101
  printf("X value: %u, expected value: %u\n", invert(x, p, n), 4);

  /* --- */

  x = 14; // b1110
  p = 0; // 1st
  n = 1;
  printf("X = %u, p = %d, n = %d\n", x, p, n);
  // 15 == b1111
  printf("X value: %u, expected value: %u\n", invert(x, p, n), 15);

  return 0;
}
