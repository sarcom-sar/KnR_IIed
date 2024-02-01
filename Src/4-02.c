#include <ctype.h>
#include <stdio.h>

#define MAXLINE 100

double my_atof(char s[]);

int main(void) {
  printf("1.2345 is %g\n", my_atof("1.2345"));
  printf("-1.2345 is %g\n", my_atof("-1.2345"));
  printf("0.00012345 is %f\n", my_atof("123.45e-6"));
  printf("-0.00012345 is %f\n", my_atof("-123.45e-6"));
  printf("0.00012345 is %f\n", my_atof("123.45E-6"));
  printf("-0.00012345 is %f\n", my_atof("-123.45E-6"));
  printf("123450 is %f\n", my_atof("123.45e+3"));
  printf("-123450 is %f\n", my_atof("-123.45e+3"));
  printf("123450 is %f\n", my_atof("123.45E+3"));
  printf("-123450 is %f\n", my_atof("-123.45E+3"));

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
    val = 10.0 * val + (s[i] - '0');
    power *= 10;
  }

  result = sign * val / power;

  if (s[i] == 'e' || s[i] == 'E') {
    i++;
    exponent = (s[i] == '-') ? -1 : 1;
    if (s[i] == '+' || s[i] == '-')
      i++;
    for (times = 0; isdigit(s[i]); i++)
      times = 10 * times + (s[i] - '0');
    while (times > 0) {
      if (exponent == -1) result /= 10;
      else result *= 10;
      times--;
    }
  }

  return result;
}
