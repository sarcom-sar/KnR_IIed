#include <stdio.h>
#include "1-16func.h"
#include "1-21func.h"

#define MAXLINE 1000
int main(void) {
  int len;
  char line[MAXLINE];

  while ((len = getaline(line, MAXLINE)) > 0) {
      print_tabbed(line);
    }
  return 0;
}
