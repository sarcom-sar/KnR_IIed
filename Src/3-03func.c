#include "3-03func.h"
#include <string.h>

void expand(char s1[], char s2[]) {
  int x = 1;
  int prev = 0;
  int next = 0;
  int len = strlen(s1);

  // pre-append, because `-` can't be a valid 0th char anyway
  s2[0] = s1[0];

  for (int i = 1; i < len; i++) {
    if (s1[i] == '-') {
      // if prev/next is not a valid char
      // skip it in logic and write to s2
      // as is
      if (!is_valid_char(s1[i - 1])) {
        s2[x++] = s1[i];
        continue;
      }
      if (!is_valid_char(s1[i + 1])) {
        s2[x++] = s1[i];
        continue;
      }

      prev = s1[i - 1];
      next = s1[i + 1]; // worst case scenario s1[len]
                        // so s1[len+1] must be \0
                        // not a valid char, so it
                        // can't happen

      expand_it(prev, next, &x, s2);

    } else { // if s1[i] is not a `-` just add it
      s2[x] = s1[i];
      x++;
    }
  }
}

int is_valid_char(int chr) {
  return (chr >= 'a' && chr <= 'z') || (chr >= 'A' && chr <= 'Z') ||
         (chr >= '0' && chr <= '9');
}

// returns negative numer if from is bigger than to
// this way we know that we have to iterate over
// valid characters by adding one to from
// for something like len_between('A', 'a') the return
// value will be too big, but that's not a problem
int len_between(int from, int to) { return (from - to); }

// expand from prev to next in s2 buffer starting at x position
void expand_it(int prev, int next, int* x, char s2[]) {
  if (len_between(prev, next) < 0) {
    // we don't want current char in s2
    // it's already in it
    prev++;
    while (prev != next) {
      if (is_valid_char(prev)) {
        s2[*x] = prev;
        (*x)++;
      }
      prev++;
    }
  } else {
    prev--;
    while (prev != next) {
      if (is_valid_char(prev)) {
        s2[*x] = prev;
        (*x)++;
      }
      prev--;
    }
  }
}
