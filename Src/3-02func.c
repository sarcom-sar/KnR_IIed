#include "3-02func.h"

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
