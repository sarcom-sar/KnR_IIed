#include "1-16func.h"
#include <stdio.h>

#define MAXLINE 1000

int main(void) {
  int len;
  char line[MAXLINE];
  int paran_balanced, curly_balanced;
  int single_balanced, double_balanced;

  paran_balanced = curly_balanced = 0;
  single_balanced = double_balanced = 0;

  while ((len = getaline(line, MAXLINE)) > 0) {
    for (int i = 0; line[i] != '\0'; i++) {
      switch (line[i]) {
      case '(':
        paran_balanced++;
        break;
      case ')':
        paran_balanced--;
        break;
      case '{':
        curly_balanced++;
        break;
      case '}':
        curly_balanced--;
        break;
      case '\"':
        double_balanced = (double_balanced) ? 0 : 1;
        break;
      case '\'':
        single_balanced = (single_balanced) ? 0 : 1;
        break;
      default:
        break;
      }
    }
  }
  printf((paran_balanced) ? "parans are not balanced\n" : "parans are balanced\n");
  printf((curly_balanced) ? "curlies are not balanced\n" : "curlies are balanced\n");
  printf((double_balanced) ? "doubles are not balanced\n" : "doubles are balanced\n");
  printf((single_balanced) ? "singles are not balanced\n" : "singles are balanced\n");
  return 0;
}
