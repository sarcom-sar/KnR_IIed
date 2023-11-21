#include "2-06func.h"

// returns xx...xnnnx...xxx
//         yy...........nnn
// where position of first n is set by p
unsigned int setbits(unsigned int x, int p, int n, unsigned int y) {
  unsigned int xmask = ~0 << n;
  unsigned int shift_by = p + 1 - n;
  return (x & ~(~xmask << shift_by)) |
    (y & ~xmask) << shift_by;
}
