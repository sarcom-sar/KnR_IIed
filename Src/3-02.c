#include <stdio.h>
#include "3-02func.h"

#define MAXLEN 1024

int main(void) {
  char escape_t[MAXLEN] = "a\t\nb";
  char escape_s[MAXLEN];
  escape(escape_s, escape_t);
  printf("t is \"%s\"\nexpected value of s is \"a\\t\\nb\", actual value is \"%s\"\n", escape_t, escape_s);

  printf("\n");

  char unescape_t[MAXLEN] = "a\\t\\nb";
  char unescape_s[MAXLEN];
  unescape(unescape_s, unescape_t);
  printf("t is \"%s\"\nexpected value of s is \"a\t\nb\", actual value is \"%s\"\n", unescape_t, unescape_s);
  return 0;
}
