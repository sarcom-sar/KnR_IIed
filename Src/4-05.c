/* Exercise 4-4. Add the commands to print the top elements of the */
/* stack without popping, to duplicate it, and to swap the top two */
/* elements. Add a command to clear the stack. */

#include "4-05func.h"
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

#define MAXOP 100
extern int sp;

int main(void) {
  int type;
  double op2;
  double temp, temp_2;
  char s[MAXOP];

  while ((type = getop(s)) != EOF) {
    switch (type) {
    case NUMBER:
      push(atof(s));
      break;
    case IDENTIFIER:
      handle_math(s);
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
    case '?':
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
    default:
      printf("error: unknown command %s\n", s);
      break;
    }
  }
  return 0;
}
