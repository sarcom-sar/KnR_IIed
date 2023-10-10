#include <stdio.h>

#define IN  1
#define OUT 0

int main(void) {
  int c, inspace;

  while ((c = getchar()) != EOF) {
    if (c == ' ' || c == '\n' || c == '\t') {
      if (inspace == OUT) {
        inspace = IN;
        putchar('\n');
      }
    } else {
      inspace = OUT;
      putchar(c);
    }
  }
  return 0;
}
