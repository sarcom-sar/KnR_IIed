#include <stdio.h>

#define IN      1
#define OUT     0
#define SPACE  32
#define DEL   127

int main(void) {
  int nchar[127] = {0}; // entire ascii table
  int c, inspace;

  while ((c = getchar()) != EOF) {
    if (c == ' ' || c == '\n' || c == '\t') {
      if (inspace == OUT) {
        inspace = IN;
      }
    } else {
      inspace = OUT;
      ++nchar[c-'\0'];
    }
  }

  // only interested in values between " " and "~"
  for (int x = SPACE; x < DEL; ++x) {
    if (nchar[x] != 0) {
      printf("%c |", x);
      for (int y = 0; y < nchar[x]; ++y) {
        putchar('#');
      }
      putchar('\n');
    }
  }
  return 0;
}
