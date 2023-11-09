#include <stdio.h>
#include "1-16func.h"
#include "2-03func.h"

#define MAXLINE 1000

int main(void) {
  char line[MAXLINE];
  int len = 0;
  long result = 0;

  while ((len = getaline(line, MAXLINE)) > 0) {
    if ((result = htoi(line)) < 0) {
      printf("no valid hex in this line\n");
    } else {
      printf("%ld\n", result);
    }
  }
  return 0;
}

