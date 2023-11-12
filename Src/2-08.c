#include <stdio.h>

unsigned int right_rot(unsigned int x, int n);

int main(void) {
  unsigned int x = 254; // b11111110
  int n = 1;
  printf("X = %u, n = %d\n", x, n);
  // 127 == b01111111
  printf("X value: %u, expected value: %u\n", right_rot(x, n), 127);

  /* --- */

  x = 128; // b1000000
  n = 3;
  printf("X = %u, n = %d\n", x, n);
  // 16 == b00010000
  printf("X value: %u, expected value: %u\n", right_rot(x, n), 16);

  /* --- */

  x = 14; // b1110
  n = 1;
  printf("X = %u, n = %d\n", x, n);
  // b0111
  printf("X value: %u, expected value: %u\n", right_rot(x, n), 7);

  return 0;
}

// returns xx...xnnnx...xxx
// where position of first n is set by p
unsigned int right_rot(unsigned int x, int n) {
  while (n > 0) {
    if ((x & 1) == 1)
      x = (x >> 1) | ~(~0U >> 1);
    else
      x = (x >> 1);
    n--;
  }
  return x;
}
