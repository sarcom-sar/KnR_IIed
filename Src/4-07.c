#include <stdio.h>
#include <string.h>

#define BUFSIZE 10
char buf[BUFSIZE];
int bufp = 0;

int getch(void) {
  return bufp > 0 ? buf[--bufp] : getchar();
}

void ungetch(int c) {
  if (bufp > BUFSIZE)
    printf("error, stack is full\n");
  else
    buf[bufp++] = c;
}

void ungets(char s[]) {
  int len = strlen(s);
  while (len > 0)
    ungetch(s[--i]);
}

int main() {
  char s[] = "I am just some string\n";
  ungets(s);
  printf("%s\n");
}

