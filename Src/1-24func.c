#include "1-24func.h"

#define ESCAPE '\\'

int check_balance(char line[], int output[4]) {
  is_two_balanced(line, "()", &output[0]);
  is_two_balanced(line, "{}", &output[1]);
  is_one_balanced(line, '\"', &output[2]);
  is_one_balanced(line, '\'', &output[3]);
  return 0;
}

int is_two_balanced(char line[], char pair[3], int* input) {
  int ignore_next = 0;
  for (int i = 0; line[i] != '\0'; i++) {
    if (ignore_next) {
      ignore_next = 0;
      continue;
    }
    if (line[i] == pair[0]) (*input)++;
    if (line[i] == pair[1]) (*input)--;
    if (line[i] == ESCAPE) ignore_next = 1;
  }
  return *input;
}

int is_one_balanced(char line[], char thing, int* input) {
  int ignore_next = 0;
  for (int i = 0; line[i] != '\0'; i++) {
    if (ignore_next) {
      ignore_next = 0;
      continue;
    }
    if (line[i] == thing) (*input) = (*input) ? 1 : 0;
    if (line[i] == ESCAPE) ignore_next = 1;
  }
  return *input;
}
