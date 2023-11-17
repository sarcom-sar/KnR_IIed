#include <stdio.h>

#define MAXLEN 1024

void escape(char to[], char from[]);
void unescape(char to[], char from[]);

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

void escape(char to[], char from[]) {
  int x = 0;
  for (int i = 0; from[i] != '\0'; i++) {
    switch (from[i]) {
    case '\n': to[x++] = '\\'; to[x++] = 'n'; break;
    case '\t': to[x++] = '\\'; to[x++] = 't'; break;
    default: to[x++] = from[i];
    }
  }
  to[x] = '\0';
}

void unescape(char to[], char from[]) {
  int j, i;
  for (i = 1, j = 0; from[i-1] != '\0'; i++) {
    switch (from[i-1]) {
    case '\\':
      if (from[i] == 't') {
        to[j++] = '\t';
        i++;
      } else if (from[i] == 'n') {
        to[j++] = '\n';
        i++;
      }
      break;
    default:
      to[j++] = from[i-1];
      break;
    }
  }
  to[j] = '\0';
}
