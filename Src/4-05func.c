#include "4-0-RPN.h"
#include "4-05func.h"
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int getop(char s[]) {
  int i = 0;
  int c;

  while ((s[0] = c = getch()) == ' ' || c == '\t')
    ;
  s[1] = '\0';

  if (isalpha(c)) {
    i = 0;
    while (isalpha(s[i++] = c))
      c = getch();
    s[i - 1] = '\0';
    if (c != EOF)
      ungetch(c);
    return IDENTIFIER;
  }

  if (!isdigit(c) && c != '.' && c != '-')
    return c;

  if (c == '-') {
    if (!isdigit(c = getch())) {
      ungetch(c);
      return '-';
    }
    s[i] = '-';
    ungetch(c);
  }
  if (isdigit(c))
    while (isdigit(s[++i] = c = getch()))
      ;
  s[i] = '\0';
  if (c != EOF)
    ungetch(c);
  return NUMBER;
}

void handle_math(char s[]) {
  if (strcmp(s, "sin") == 0) {
    push(sin(pop()));
  } else if (strcmp(s, "cos") == 0) {
    push(cos(pop()));
  } else if (strcmp(s, "exp") == 0) {
    push(exp(pop()));
  } else if (strcmp(s, "pow") == 0) {
    double second = pop();
    push(pow(pop(), second));
  } else {
    printf("%s is not a valid func\n", s);
  }
}
