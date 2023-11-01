#include "1-23func.h"

int trim_comments(char line[], int* in_multi_line_comment) {
  int i = 0;
  int save_pos = 0;
  int first_char_pos = 0;

  for (int y = 0; line[y] != '\0'; y++) {
    if (line[y] == ' ' || line[y] == '\t') continue;
    first_char_pos = y;
    break;
  }

  for (; line[i] != '\0'; i++) {
    if (i > 0) {
      if (line[i-1] == '/' && line[i] == '/') {
        line[i-1] = '\n';
        line[i] = '\0';
        break;
      }
      if (line[i] == '*' && line[i-1] == '/') {
        *in_multi_line_comment = 1;
        save_pos = i-1;
        line[save_pos] = '\0';
      }
      if (line[i] == '/' && line[i-1] == '*') {
        *in_multi_line_comment = 0;
        i++;
        while (line[i] != '\0') {
          line[save_pos] = line[i];
          save_pos++;
          i++;
        }
        line[save_pos] = '\0';
      }
      // drop the comment until it ends
      if (*in_multi_line_comment == 1)
        if (line[i] == '\n')
          line[first_char_pos-1] = '\0';
    }
  }
  return i;
}
