#include <stdio.h>
#include "1-16func.h"
#include "1-22func.h"

#define MAXLINE 1000

int main(void) {
  int len = 0;
  char line[MAXLINE];
  while ((len = getaline(line, MAXLINE)) > 0) {
    break_line(line);
    printf("%s", line);
  }
  return 0;
}
