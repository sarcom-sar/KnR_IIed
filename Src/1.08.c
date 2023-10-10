#include <stdio.h>

int main(void) {
  int c;
  long nl, nb, nt;
  nl = (nb = (nt = 0));

  while ((c = getchar()) != EOF) {
    if (c == '\n') ++nl;
    if (c == ' ') ++nb;
    if (c == '\t') ++nt;
  }
  printf("newlines = %d\nblanks = %d\ntabs = %d\n", nl, nb, nt);
  return 0;
}
