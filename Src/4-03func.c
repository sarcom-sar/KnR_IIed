#include "4-0-RPN.h"
#include "4-03func.h"
#include <stdio.h>
#include <ctype.h>

int getop(char s[]) {
  int i, c;

  while ((s[0] = c = getch()) == ' ' || c == '\t')
    ;
  s[1] = '\0';
  if (!isdigit(c) && c != '.' && c != '-')
    return c;

  i = 0;
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
