#include "1-24func.h"

#define ESCAPE       '\\'
#define DOUBLE_QUOT  '\"'
#define SINGLE_QUOT  '\''
#define PAREN_START  '('
#define PAREN_END    ')'
#define SQUARE_START '['
#define SQUARE_END   ']'
#define CURLY_START  '{'
#define CURLY_END    '}'

int init_balance_queue(struct balance_queue* bq) {
  bq->last_point = MAX;
  for (int i = 0; i < MAX; i++) {
    bq->queue[i][0] = 0;
    bq->queue[i][1] = 0;
    bq->queue[i][2] = 0;
  }
  return 0;
}

int init_balance_state(struct balance_state* bs) {
  bs->curr_line = 0;
  bs->is_escape = 0;
  bs->is_in_quote = 0;
  bs->queue_point = 0;
  return 0;
}

int queue_add(char ch, int i, struct balance_queue *bq,  \
              struct balance_state *bs) {
  bq->queue[bs->queue_point][0] = bs->curr_line;
  bq->queue[bs->queue_point][1] = i;
  bq->queue[bs->queue_point][2] = ch;
  bs->queue_point++;
  return bs->queue_point;
}

int queue_zero(int point, struct balance_queue *bq) {
  bq->queue[point][0] = 0;
  bq->queue[point][1] = 0;
  bq->queue[point][2] = 0;
  return 0;
}


int check_balance(char line[], struct balance_queue* bq, \
                  struct balance_state* bs) {
  for (int i = 0; line[i] != '\0'; i++) {
    // skip over next character
    if (bs->is_escape) {
      bs->is_escape = 0;
      continue;
    }
    if (line[i] == ESCAPE) {
      bs->is_escape = 1;
    }
    // ignore everything until closing quote
    if (line[i] == DOUBLE_QUOT || line[i] == SINGLE_QUOT) {
      bs->is_in_quote = (bs->is_in_quote) ? 0 : 1;
    }

    if (!(bs->is_in_quote)) {
      switch (line[i]) {
      case PAREN_START:
        queue_add(line[i], i, bq, bs);
        break;
      case PAREN_END:
        queue_add(line[i], i, bq, bs);
        break;
      case SQUARE_START:
        queue_add(line[i], i, bq, bs);
        break;
      case SQUARE_END:
        queue_add(line[i], i, bq, bs);
        break;
      case CURLY_START:
        queue_add(line[i], i, bq, bs);
        break;
      case CURLY_END:
        queue_add(line[i], i, bq, bs);
        break;
      }
    }
  }
  bs->curr_line++;
  return 0;
}


int reduce_queue(struct balance_queue* bq, struct balance_state* bs) {
  int is_found = 0;
  for (int i = (bs->queue_point)-1; i >= 0; i--) {
    switch(bq->queue[i][2]) {
    case PAREN_START:
      find_prev(i, &is_found, PAREN_END, bq);
      break;
    case SQUARE_START:
      find_prev(i, &is_found, SQUARE_END, bq);
      break;
    case CURLY_START:
      find_prev(i, &is_found, CURLY_END, bq);
      break;
    }
  }
  return 0;
}

int find_prev(int i, int* is_found, char opposite_type, struct balance_queue* bq) {
  for (int save = i; save >= 0; save--) {
    // zero this point
    if (bq->queue[save][2] == opposite_type) {
      queue_zero(save, bq);
      *is_found = 1;
      break;
    }
  }
  if (*is_found) {
    queue_zero(i, bq);
    *is_found = 0;
  }
  return *is_found;
}
