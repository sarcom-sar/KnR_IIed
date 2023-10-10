#include <stdio.h>

int main(void) {
  int c;
  int trailing = 0;

  while ((c = getchar()) != EOF) {
    if (c == ' ') {
      if (trailing != 1) putchar(c);
      trailing = 1;
    } else {
      putchar(c);
      trailing = 0;
    }
  }
  return 0;
}
