#include "1-16func.h"
#include "1-24func.h"
#include <stdio.h>

#define MAXLINE 1000

int main(void) {
  int len;
  char line[MAXLINE];
  int balance_types[4] = {0, 0, 0, 0};

  while ((len = getaline(line, MAXLINE)) > 0) {
    check_balance(line, balance_types);
  }

  printf("parenthesis %s balanced\n", ((balance_types[0]) ? "are not" : "are"));
  printf("curly braces %s balanced\n", ((balance_types[1]) ? "are not" : "are"));
  printf("double quotations %s balanced\n", ((balance_types[2]) ? "are not" : "are"));
  printf("single quotations %s balanced\n", ((balance_types[3]) ? "are not" : "are"));
  return 0;
}
