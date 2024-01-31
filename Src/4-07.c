#include <stdio.h>
#include <string.h>

#define BUFSIZE 100
char buf[BUFSIZE];
int bufp = 0;

int getch(void) {
  return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c) {
  if (bufp > BUFSIZE)
    printf("error, stack is full\n");
  else
    buf[bufp++] = c;
}

void ungets(char s[]) {
  int i = strlen(s);
  while (i > 0)
    ungetch(s[--i]);
}

int main() {
  char s[] = "I am just some string\n";
  int c;

  ungets(s);
  while ((c = getch()) != EOF)
    putchar(c);
}

