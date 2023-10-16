#include <stdio.h>
#include "1-16func.h"

#define MAXLINE    1000
#define PRINTSTART 80

int main(void) {
  int len;
  char line[MAXLINE];

  while ((len = getaline(line, MAXLINE)) > 0)
    if (len >= PRINTSTART)
      printf("%s", line);

  return 0;
}
