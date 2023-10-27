/* Possible tests include,
   - no input at all
   - one character word
   - two character word
   - only newlines
   - only whitespace
   - one word per line
   - word after some blanks */

#include <stdio.h>

#define IN  1
#define OUT 0

int main(void) {
  int c, nl, nw, nc, state;

  state = OUT;
  nl = nw = nc = 0;
  while ((c = getchar()) != EOF) {
    ++nc;
    if (c == '\n') {
      ++nl;
    }
    if (c == ' ' || c == '\n' || c == '\t') {
      state = OUT;
    } else if (state == OUT) {
      state = IN;
      ++nw;
    }
  }

  printf("%d %d %d", nl, nw, nc);
}
