#include <stdio.h>
#include "1-16func.h"
#include "1-23func.h"
// test
#define MAXLINE 1000

int main(void) {
  char line[MAXLINE];
  int len; // length of the line
  int in_multi_line_comment = 0;

  // len is truly useless here but it tests the program
  while ((len = getaline(line, MAXLINE)) > 0) {
    /* one line comment to check correctness of it all */len = trim_comments(line, &in_multi_line_comment);
    printf("%s", line);
  }
}
