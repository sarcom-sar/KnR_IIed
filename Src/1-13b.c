#include <stdio.h>

#define IN  1
#define OUT 0
#define BIG_NUM 72

int main(void) {
  int c, inspace, i, max_height, x;
  i = 0;
  x = 0;
  max_height = 0;
  int count_words[BIG_NUM] = {0};

  while ((c = getchar()) != EOF) {
    if (i == BIG_NUM) break;
    if (c == ' ' || c == '\n' || c == '\t') {
      if (inspace == OUT) {
        inspace = IN;
        ++i;
      }
    } else {
      inspace = OUT;
      count_words[i] = count_words[i] + 1;
    }
  }

  // find longest word
  for (x = 0; x < i; x++) {
    if (count_words[x] > max_height)
      max_height = count_words[x];
  }

  // draw on the screen starting with longest word
  for ( ; max_height >= 0; --max_height) {
    printf("%3.d | ", max_height+1);
    for (x = 0; x < i; ++x) {
      if (count_words[x] > max_height) {
        printf("# ");
      } else {
        printf("  ");
      }
    }
    putchar('\n');
  }

  return 0;
}
