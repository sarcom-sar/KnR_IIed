#include <stdio.h>
#include <limits.h>

#define LIMIT_SIGNED(TYPE) ((unsigned TYPE) ~0 >> 1)
#define LIMIT_UNSIGNED(TYPE) ((unsigned TYPE) ~0)

int main (void) {
  // from limits.h
  printf("SCHAR_MIN %d\n", SCHAR_MIN);
  printf("SCHAR_MAX %d\n", SCHAR_MAX);
  printf("UCHAR_MAX %d\n", UCHAR_MAX);
  printf("SHRT_MIN %d\n", SHRT_MIN);
  printf("SHRT_MAX %d\n", SHRT_MAX);
  printf("USHRT_MAX %d\n", USHRT_MAX);
  printf("INT_MIN %d\n", INT_MIN);
  printf("INT_MAX %d\n", INT_MAX);
  printf("UINT_MAX %u\n", UINT_MAX);
  printf("LONG_MIN %ld\n", LONG_MIN);
  printf("LONG_MAX %ld\n", LONG_MAX);
  printf("ULONG_MAX %lu\n", ULONG_MAX);

  printf("\n");

  // manual computation
  // it's off by one because defined
  // types include zero into definition
  printf("SCHAR_MIN %d\n", -(char)LIMIT_SIGNED(char));
  printf("SCHAR_MAX %d\n", (char)LIMIT_SIGNED(char));
  printf("UCHAR_MAX %d\n", LIMIT_UNSIGNED(char));
  printf("SHRT_MIN %d\n", -(short)LIMIT_SIGNED(short));
  printf("SHRT_MAX %d\n", (short)LIMIT_SIGNED(short));
  printf("USHRT_MAX %d\n", LIMIT_UNSIGNED(short));
  printf("INT_MIN %d\n", -(int)LIMIT_SIGNED(int));
  printf("INT_MAX %d\n", (int)LIMIT_SIGNED(int));
  printf("UINT_MAX %u\n", LIMIT_UNSIGNED(int));
  printf("LONG_MIN %ld\n", -(long)LIMIT_SIGNED(long));
  printf("LONG_MAX %ld\n", (long)LIMIT_SIGNED(long));
  printf("ULONG_MAX %lu\n", LIMIT_UNSIGNED(long));
  return 0;
}

