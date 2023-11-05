#include "1-16func.h"
#include "1-24func.h"
#include <stdio.h>

#define MAXLINE 1000
#define MAX     1000

int main(void) {
  int len;
  char line[MAXLINE];
  struct balance_queue b_que;
  struct balance_state b_stat;

  //init 
  init_balance_queue(&b_que);
  init_balance_state(&b_stat);

  // iterate over all lines
  while ((len = getaline(line, MAXLINE)) > 0) {
    check_balance(line, &b_que, &b_stat);
  }

  // reduce lines
  int is_found = 0;
  for (int i = b_stat.queue_point-1; i >= 0; i--) {
    if (b_que.queue[i][2] == ')') {
      for (int save = i; save >= 0; save--) {
        // zero this point
        if (b_que.queue[save][2] == '(') {
          b_que.queue[save][0] = 0;
          b_que.queue[save][1] = 0;
          b_que.queue[save][2] = 0;
          is_found = 1;
          break;
        }
      }
      if (is_found) {
        is_found = 0;
        b_que.queue[i][0] = 0;
        b_que.queue[i][1] = 0;
        b_que.queue[i][2] = 0;
      }
    }
    if (b_que.queue[i][2] == ']') {
      for (int save = i; save >= 0; save--) {
        // zero this point
        if (b_que.queue[save][2] == '[') {
          b_que.queue[save][0] = 0;
          b_que.queue[save][1] = 0;
          b_que.queue[save][2] = 0;
          is_found = 1;
          break;
        }
      }
      if (is_found) {
        is_found = 0;
        b_que.queue[i][0] = 0;
        b_que.queue[i][1] = 0;
        b_que.queue[i][2] = 0;
      }
    }
    if (b_que.queue[i][2] == '}') {
      for (int save = i; save >= 0; save--) {
        // zero this point
        if (b_que.queue[save][2] == '{') {
          b_que.queue[save][0] = 0;
          b_que.queue[save][1] = 0;
          b_que.queue[save][2] = 0;
          is_found = 1;
          break;
        }
      }
      if (is_found) {
        is_found = 0;
        b_que.queue[i][0] = 0;
        b_que.queue[i][1] = 0;
        b_que.queue[i][2] = 0;
      }
    }
  }

  // print lines
  for (int i = 0; i < b_stat.queue_point; i++) {
    if (b_que.queue[i][2] != 0) {
      printf("Unbalanced %c at line %d, char %d\n", b_que.queue[i][2], b_que.queue[i][0]+1, b_que.queue[i][1]+1);
    }
  }

  return 0;
}
