/* Add commands for handling variables. (It's easy */
/* to provide twenty-six variables with single-letter names.) Add */
/* a variable for the most recently printed value. */

#include "4-06func.h"
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

#define MAXOP 100
extern int sp;
extern double varlist[26];

int main(void) {
  int type;
  double op2;
  double temp, temp_2;
  char s[MAXOP];
  char last_var = 0;

  while ((type = getop(s)) != EOF) {
    switch (type) {
    case NUMBER:
      push(atof(s));
      break;
    case IDENTIFIER:
      handle_math(s);
      break;
    case VARIABLE:
      last_var = s[0];
      push(varlist[s[0] - 'a']);
      break;
    case '+':
      push(pop() + pop());
      break;
    case '*':
      push(pop() * pop());
      break;
    case '-':
      op2 = pop();
      push(pop() - op2);
      break;
    case '/':
      op2 = pop();
      if (op2 != 0.0)
        push(pop() / op2);
      else
        printf("error: zero divisor\n");
      break;
    case '%':
      op2 = pop();
      if (op2 <= 0.0)
        printf("error: negative number\n");
      else
        push((int)pop() % (int)op2);
      break;
    case '\n':
      break;
    case '@':
      temp = pop();
      printf("%.8g\n", temp);
      push(temp);
      break;
    case '#':
      temp = pop();
      push(temp);
      push(temp);
      break;
    case '~':
      temp = pop();
      temp_2 = pop();
      push(temp);
      push(temp_2);
      break;
    case '!':
      while (sp != 0) {
        pop();
      }
      break;
    case '=':
      // previous value of variable
      pop();
      varlist[last_var - 'a'] = pop();
      break;
    case '_':
      push(varlist[last_var - 'a']);
      break;
    case '?':
      printf("@ - print last value on stack\n");
      printf("# - duplicate value\n");
      printf("~ - swap two values\n");
      printf("! - clean stack\n");
      printf("= - assign value to variable\n");
      printf("_ - value of last printed variable\n");
      printf("a..z - possible variables\n");
      printf("pow, cos, exp, sin are handled\n");
      break;
    default:
      printf("error: unknown command %s\n", s);
      break;
    }
  }
  return 0;
}
