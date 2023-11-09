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
  printf("newlines = %ld\nblanks = %ld\ntabs = %ld\n", nl, nb, nt);
  return 0;
}
