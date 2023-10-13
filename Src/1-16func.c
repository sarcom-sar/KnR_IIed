#include <stdio.h>
#include "1-16func.h"

int getaline(char line[], int maxline) {
  int i, c;
  for (i = 0; i < maxline - 1 && \
         (((c = getchar()) != EOF) && \
          (c != '\n')); ++i)
    line[i] = c;

  if (c == '\n') {
    line[i] = c;
    ++i;
  }
  line[i] = '\0';

  return i;
}

void copy(char from[], char to[]) {
  int i = 0;

  while ((to[i] = from[i]) != '\0')
    ++i;
}
