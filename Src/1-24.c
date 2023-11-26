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

  reduce_lines(&b_que, b_stat.queue_point);
  // print lines
  for (int i = 0; i < b_stat.queue_point; i++) {
    if (b_que.queue[i][2] != 0) {
      printf("Unbalanced %c at line %d, char %d\n", b_que.queue[i][2], b_que.queue[i][0]+1, b_que.queue[i][1]+1);
    }
  }

  return 0;
}
