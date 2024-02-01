#include "4-0-RPN.h"
#include "4-06func.h"
#include "1-16func.h"
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

#define MAXLINE 1000

char line[MAXLINE] = {0};
int linep = 0;

int getop(char s[]) {
  int i = 0;
  int c;

  if (line[linep] == '\0')
    if (getaline(line, MAXLINE) == 0)
      return EOF;
    else
      linep = 0;

  while ((s[0] = c = line[linep++]) == ' ' || c == '\t')
    ;
  s[1] = '\0';

  if (isalpha(c)) {
    i = 0;
    while (isalpha(s[i++] = c))
      c = line[linep++];
    s[i - 1] = '\0';
    if (c != EOF)
      linep--;
    if (i == 2) return VARIABLE;
    return IDENTIFIER;
  }

  if (!isdigit(c) && c != '.' && c != '-')
    return c;

  if (c == '-') {
    if (!isdigit(c = line[linep++])) {
      linep--;
      return '-';
    }
    s[i] = '-';
    linep--;
  }
  if (isdigit(c))
    while (isdigit(s[++i] = c = line[linep++]))
      ;
  s[i] = '\0';
  if (c != EOF)
    linep--;
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
