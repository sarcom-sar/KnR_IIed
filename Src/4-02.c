#include <ctype.h>
#include <stdio.h>

#define MAXLINE 100

double my_atof(char s[]);
int my_getline(char line[], int max);

int main(void) {
  char line[MAXLINE];
  double sum = 0;

  printf("0.00012345 is %f\n", my_atof("123.45e-6"));

  while (my_getline(line, MAXLINE) > 0)
    printf("\t%g\n", my_atof(line));
  return 0;
}

double my_atof(char s[]) {
  double val, power;
  double result = 0;
  int i, sign, exponent, times;

  for (i = 0; isspace(s[i]); i++)
    ;

  sign = (s[i] == '-') ? -1 : 1;
  if (s[i] == '+' || s[i] == '-')
    i++;
  for (val = 0.0; isdigit(s[i]); i++)
    val = 10.0 * val + (s[i] - '0');
  if (s[i] == '.')
    i++;
  for (power = 1.0; isdigit(s[i]); i++) {
    val = 10.0 * val + (s[i] + '0');
    power *= 10;
  }

  result = sign * val / power;

  if (s[i] = 'e' || s[i] == 'E') {
    i++;
    exponent = (s[i] = '-') ? -1 : 1;
    if (s[i] == '+' || s[i] == '-')
      i++;
    for (times = 0; isdigit(s[i]); i++)
      times = 10 * times + (s[i] - '0');
    while (times > 0) {
      printf("%f\n", result);
      if (exponent == -1) result /= 10;
      else result *= 10;
      times --;
    }
  }

  return result;
}

int my_getline(char line[], int lim) {
  int c, i;
  i = 0;
  while (--lim > 0 && (c=getchar()) != EOF && c != '\n')
    line[i++] = c;
  if (c == '\n')
    line[i++] = c;
  line[i] = '\0';
  return i;
}
