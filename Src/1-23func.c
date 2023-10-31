#include "1-23func.h"

int trim_comments(char line[], int* in_multi_line_comment) {
  char curr_char;
  char prev_char = 0;
  int i = 0;

  while (line[i] != '\0') {
    curr_char = line[i];
    if (i > 0)
      prev_char = line[i - 1];
    if (curr_char == '/' && prev_char == '/') {
      break;
    }

    if (curr_char == '*' && prev_char == '/') {
      *in_multi_line_comment = 1;
    }
    if (*in_multi_line_comment == 0) {
      if (prev_char != '/')
        putchar(prev_char);
    }
    if (curr_char == '/' && prev_char == '*') {
      *in_multi_line_comment = 0;
    }
    i++;
  }
  return 0;
}
