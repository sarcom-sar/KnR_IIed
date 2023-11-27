#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 1000

/*
 * Biggest possible number in two compliment is written as,
 * n = -(2^(wordsize-1)), while biggest possible positive number
 * is n = 2^(wordsize-1) - 1, you can't represent it that way.
 */

void itoa(int n, char s[]);
void reverse(char s[]);

int main(void) {
  char s[MAX] = {0};
  itoa(256, s);
  printf("%s\n", s);

  char z[MAX] = {0};
  itoa(-256, z);
  printf("%s\n", z);
}

void itoa(int n, char s[]) {
  int i;
  int sign = n;

  i = 0;
  do {
    s[i++] = abs(n % 10) + '0';
  } while ((n /= 10) != 0);
  if (sign < 0)
    s[i++] = '-';
  s[i] = '\0';
  reverse(s);
}

void reverse(char s[]) {
  int c, i, j;

  for (i = 0, j = strlen(s) - 1; i < j; ++i, --j) {
    c = s[i];
    s[i] = s[j];
    s[j] = c;
  }
}
