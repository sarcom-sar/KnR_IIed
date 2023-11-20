#include "2-08func.h"

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
