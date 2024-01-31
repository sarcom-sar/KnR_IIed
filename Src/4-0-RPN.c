#include "4-0-RPN.h"
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

int getch(void) { return (bufp > -1) ? buf[--bufp] : getchar(); }

void ungetch(int c) {
  if (bufp >= BUFSIZE)
    printf("ungetch: too many characters\n");
  else
    buf[bufp++] = c;
}
