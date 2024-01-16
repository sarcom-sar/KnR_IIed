#include "4-03func.h"
#include <stdio.h>
#include <ctype.h>

int sp = 0;
double val[MAXVAL];
char buf[BUFSIZE];
int bufp = 0;

void push(double f) {
  if (sp < MAXVAL)
    val[sp++] = f;
  else
    printf("error: stack full, can't push %g\n", f);
}

double pop(void) {
  if (sp > 0)
    return val[--sp];
  else
    printf("error: stack empty\n");
  return 0.00;
}

int getop(char s[]) {
  int i, c;
  int neg_flag = 0;

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

int getch(void) { return (bufp > 0) ? buf[--bufp] : getchar(); }

void ungetch(int c) {
  if (bufp >= BUFSIZE)
    printf("ungetch: too many characters\n");
  else
    buf[bufp++] = c;
}
