#include <stdio.h>

char *rec_itoa(int n, char *s, int base) {
  int d = n % base;
  int r = n / base;
  if (n < 0) {
    *s++ = '-';
    d = -d;
    r = -r;
  }
  if (r)
    s = rec_itoa(r, s, base);
  *s++ = "0123456789abcdefghijklmnoprstuvwxyz"[d];
  *s = 0;
  return s;
}

int main(void) {
  char s[10] = {0};
  rec_itoa(2968, s, 10);
  printf("%s\n", s);
  rec_itoa(-125, s, 10);
  printf("%s\n", s);
}
