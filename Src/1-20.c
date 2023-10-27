#include <stdio.h>
#include "1-16func.h"
#include "1-20func.h"

#define MAXLINE 1000

int main (void) {
  int len = 0;
  char line[MAXLINE];

  while ((len = getaline(line, MAXLINE)) > 0) {
    print_tabless(line);
  }

  return 0;
}
