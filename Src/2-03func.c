#include "2-03func.h"
#include <stdio.h>

#define BASE    16

struct hex_pos find_next_hex(char line[]) {
  int in_hex = 0;
  int start_pos = 0;
  int end_pos = 0;

  for (int i = 0; line[i] != EOF; i++) {
    if (line[i] == '0')
      in_hex++; // almost in hex mode
    if (line[i] == 'x' && in_hex == 1)
      in_hex++; // fully in hex mode

    if (in_hex == 2) { // start of hex number
      start_pos = i + 1;
      in_hex = 3;
    }
    if (in_hex == 3)
      if (line[i] == ' ' || line[i] == '\n') { // end of hex number
        end_pos = i - 1;
        break;
      }
  }

  struct hex_pos hp;
  hp.start_pos = start_pos;
  hp.end_pos = end_pos;

  return hp;
}

long htoi(char line[]) {
  long ret_num = 0;
  int len = 0;

  // find length of hex number
  struct hex_pos hp = find_next_hex(line);

  if (hp.start_pos == 0) {
    return -1; // no hex number here
  }

  // amount of digits in supposed hex value
  len = hp.end_pos - hp.start_pos;

  for (int i = hp.start_pos; i <= hp.end_pos; i++) {
    if (line[i] >= '0' && line[i] <= '9') {
      ret_num += (line[i] - '0') * sqrt_q(BASE, len);
    } else if (line[i] >= 'a' && line[i] <= 'f') {
      ret_num += ((line[i] - 'a') + 10) * sqrt_q(BASE, len);
    } else if (line[i] >= 'A' && line[i] <= 'F') {
      ret_num += ((line[i] - 'A') + 10) * sqrt_q(BASE, len);
    } else {
      return -1;
    }
    len--;
  }

  return ret_num;
}

long sqrt_q(int num, int exp) {
  if (exp < 0) return -1;
  if (exp == 0) return 1;
  for (int i = 1; i < exp; i++) {
    num *= num;
  }
  return num;
}
