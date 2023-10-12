#include <stdio.h>

#define IN      1
#define OUT     0
#define SPACE  32
#define DEL   127

int main(void) {
  int nchar[127] = {0}; // entire ascii table
  int c, inspace, max_height, x;
  max_height = 0;
  x = 0;

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

  // find which character got the most use
  for (x = 0; x < DEL; x++) {
    if (nchar[x] > max_height)
      max_height = nchar[x];
  }

  // draw vertically
  // only interested in values between " " and "~"
  for ( ; max_height >= 0; --max_height) {
    printf("%3.d|", max_height+1);
    for (int x = SPACE; x < DEL; ++x) {
      if (nchar[x] > 0)
        if (nchar[x] > max_height) {
          printf("# ");
        } else {
          printf("  ");
        }
    }
    putchar('\n');
  }
  printf("    ");
  for (x = 0; x < DEL; x++) {
    if (nchar[x] > 0)
        printf("%c ", x);
  }
  putchar('\n');
  return 0;
}
