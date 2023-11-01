#include "1-23func.h"

int trim_comments(char line[], int* in_multi_line_comment) {
  int i = 0;
  int save_pos = 0;

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
        break;
      }
      // drop the comment until it ends
      if (*in_multi_line_comment == 1) continue;
    }
  }
  return i;
}
