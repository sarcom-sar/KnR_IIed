#ifndef A124
#define A124

#define MAX 1000

struct balance_queue {
  int last_point;
  int queue[MAX][3];
};

struct balance_state {
  int is_escape;
  int is_in_quote;
  int curr_line;
  int queue_point;
};

int init_balance_queue(struct balance_queue* bq);
int init_balance_state(struct balance_state* bs);
int queue_add(char ch, int i, struct balance_queue* bq, struct balance_state* bs);
int check_balance(char line[], struct balance_queue* bq, struct balance_state* bs);

#endif
