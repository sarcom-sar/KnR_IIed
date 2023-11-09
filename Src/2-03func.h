#ifndef A203
#define A203

struct hex_pos {
  int start_pos;
  int end_pos;
};

struct hex_pos find_next_hex(char line[]);

// for small values of hex values
long htoi(char line[]);

// quick and dirty, works for small values of exp
long sqrt_q(int num, int exp);

#endif
