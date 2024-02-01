#include <stdio.h>
#include <string.h>

/*
   getch/ungetch do not handle EOF, because EOF is traditionally -1
   you can do a work around by making char buff an int array, because
   then it will see EOF as -1 instead of rolling over (if char is 0-255)
   this solution is lazy though.
*/

#define BUFSIZE 100
/* int buf[BUFSIZE]; */
char buf[BUFSIZE];
int bufp = 0;

int getch(void) {
  return (bufp > 0) ? buf[--bufp] : getchar();
}

/* explicitly check for EOF */
void ungetch(int c) {
  if (bufp > BUFSIZE)
    printf("error, stack is full\n");
  else if (c != EOF)
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

