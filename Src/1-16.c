#include <stdio.h>
#include "1-16func.h"

#define MAXLINE 1000

int main (void) {
  int len, maxlen;
  char line[MAXLINE], maxline[MAXLINE];

  maxlen = 0;
  while ((len = getaline(line, MAXLINE)) > 0) {
    if (len > maxlen) {
      maxlen = len;
      copy(line, maxline);
    }
  }

  if (maxlen > 0)
    printf("%s", maxline);

  return 0;
}
