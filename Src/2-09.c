#include <stdio.h>

int bitcount_slow(unsigned int x);
int bitcount_fast(unsigned int x);

int main(void) {
  printf("b = %d, it has %d bits for bitcount_slow\n", 1, bitcount_slow(1));
  printf("b = %d, it has %d bits for bitcount_slow\n", 255, bitcount_slow(255));
  printf("b = %d, it has %d bits for bitcount_slow\n", 2137, bitcount_slow(2137));

  printf("b = %d, it has %d bits for bitcount_fast\n", 1, bitcount_fast(1));
  printf("b = %d, it has %d bits for bitcount_fast\n", 255, bitcount_fast(255));
  printf("b = %d, it has %d bits for bitcount_fast\n", 2137, bitcount_fast(2137));
}

// has to check every single bit like so,
// 101 & 01 = true; b++; x>>1
// 010 & 01 = false; x>>1
// 001 & 01 = true; b++; x>>1
// b == 2
int bitcount_slow(unsigned int x) {
  int b;
  for (b = 0; x != 0; x >>= 1) {
    if (x & 01)
      b++;
  }
  return b;
}

// x &= (x-1) = x & (x-1)
// above equation combines what for() and check x&01 do
// in single function, like so
// x = 101 & 100 = 100; b++
// x = 100 & 011 = 000; b++
// x = 0
int bitcount_fast(unsigned int x) {
  int b = 0;
  while (x > 0){
    x &= (x - 1);
    b++;
  }
  return b;
}
