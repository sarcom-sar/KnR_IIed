#include "2-07func.h"

// returns xx...xnnnx...xxx
// where position of first n is set by p
unsigned int invert(unsigned int x, int p, int n) {
  unsigned int xmask = ~0 << n;
  unsigned int shift_by = p + 1 - n;
  return x ^ (~xmask << shift_by);
}
