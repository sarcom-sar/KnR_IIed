#include <stdio.h>

#define MAXLINE 1000

int main(void) {
  int c, i;
  char line[MAXLINE];

  for (i = 0; i < MAXLINE-1; i++) {
    c = getchar();
    if (c == '\n') break;
    if (c == EOF)
      break;
    line[i] = c;
  }

  if (c == '\n') {
    line[i] = c;
    ++i;
  }
  line[i] = '\0';

  printf("%s", line);
  return 0;
}
