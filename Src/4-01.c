#include <stdio.h>
#include <string.h>

#define MAX 1000

int getaline(char line[], int lim);
int strindex(char source[], char searchfor[]);

char pattern[] = "ould";

int main(void) {
  char line[MAX];
  int found = 0;
  int right_pos = 0;

  while (getaline(line, MAX) > 0)
    if ((right_pos = strindex(line, pattern)) >= 0) {
      printf("%s", line);
      printf("rightmost position of pattern is %d\n", right_pos);
      found++;
    }
  return found;
}

int getaline(char line[], int lim) {
  int c, i;

  i = 0;
  while (--lim > 0 && (c=getchar()) != EOF && c != '\n')
    line[i++] = c;
  if (c == '\n')
    line[i++] = c;
  line[i] = '\0';
  return i;
}

int strindex(char source[], char searchfor[]) {
  int i, j, k;
  for (i = strlen(source) - strlen(searchfor); i >= 0; i--) {
    for (j=i, k=0; searchfor[k] != '\0' && \
           source[j]==searchfor[k]; j++, k++)
      ;
    if (k > 0 && searchfor[k] == '\0')
      return i;
  }
  return -1;
}
