#include <stdio.h>
#include "2-09func.h"

int main(void) {
  printf("b = %d, it has %d bits for bitcount_slow\n", 1, bitcount_slow(1));
  printf("b = %d, it has %d bits for bitcount_slow\n", 255, bitcount_slow(255));
  printf("b = %d, it has %d bits for bitcount_slow\n", 2137, bitcount_slow(2137));

  printf("b = %d, it has %d bits for bitcount_fast\n", 1, bitcount_fast(1));
  printf("b = %d, it has %d bits for bitcount_fast\n", 255, bitcount_fast(255));
  printf("b = %d, it has %d bits for bitcount_fast\n", 2137, bitcount_fast(2137));
}

