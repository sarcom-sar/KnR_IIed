#include <stdio.h>
#include "1-16func.h"
#include "1-19func.h"

#define MAXLINE 1000

int main() {
  char line[MAXLINE];
  int len = 0;

  while ((len = getaline(line, MAXLINE)) > 0) {
    reverse_line(line, len);
    printf("%s", line);
  }

  return 0;
}
