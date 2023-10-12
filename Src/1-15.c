#include <stdio.h>
#include "1-15func.h"

int main(void) {
  int fahr = 300;

  for (int step = 20; fahr >= 0; fahr -= step) {
    printf("%3d\t%6.1f\n", fahr, conversion(fahr));
  }

  return 0;
}
