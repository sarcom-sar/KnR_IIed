#include <stdio.h>
#include "2-06func.h"

int main(void) {
  unsigned int x = 255; // b11111111 
  unsigned int y = 1;   // b00000001
  int p = 3; // 4th
  int n = 3; // flip 3 bits to 001 
  printf("X = %u, Y = %u, p = %d, n = %d\n", x, y, p, n);
  // 243 == b11110011
  printf("X value: %u, expected value: %u\n", setbits(x, p, n, y), 243);

  /* --- */

  x = 170; // b10101010
  y = 85;  // b01010101
  p = 7; // 8th bit
  n = 4; // flip 3 bits to 0101
  printf("X = %u, Y = %u, p = %d, n = %d\n", x, y, p, n);
  // 90 == b01011010
  printf("X value: %u, expected value: %u\n", setbits(x, p, n, y), 90);

  /* --- */

  x = 238; // b11101110
  y = 17;  // b00010001
  p = 4; // 5th bit
  n = 1; // flip 1 bit to 1
  printf("X = %u, Y = %u, p = %d, n = %d\n", x, y, p, n);
  // 254 == b11111110
  printf("X value: %u, expected value: %u\n", setbits(x, p, n, y), 254);
  return 0;
}
