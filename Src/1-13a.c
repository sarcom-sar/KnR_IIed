#include <stdio.h>

#define IN  1
#define OUT 0

int main(void) {
  int c, inspace, counter;

  while ((c = getchar()) != EOF) {
    if (c == ' ' || c == '\n' || c == '\t') {
      if (inspace == OUT) {
        inspace = IN;
      }
      if (counter != 0) {
        for ( ; counter > 0; --counter) putchar('#');
        putchar('\n');
      }
    } else {
      inspace = OUT;
      ++counter;
    }
  }
  return 0;
}
