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


int queue_add(char ch, int i, struct balance_queue *bq,  \
              struct balance_state *bs) {
  bq->queue[bs->queue_point][0] = bs->curr_line;
  bq->queue[bs->queue_point][1] = i;
  bq->queue[bs->queue_point][2] = ch;
  bs->queue_point++;
  return bs->queue_point;
}

void zero_el_queue(struct balance_queue* bq, int save) {
  bq->queue[save][0] = 0;
  bq->queue[save][1] = 0;
  bq->queue[save][2] = 0;
}

void reduce_lines(struct balance_queue *bq, int queue_point) {
  for (int i = queue_point - 1; i >= 0; i--) {
    switch (bq->queue[i][2]) {
    case PAREN_END:
      check_for_unmatched(i, bq, PAREN_START);
      break;
    case CURLY_END:
      check_for_unmatched(i, bq, CURLY_START);
      break;
    case SQUARE_END:
      check_for_unmatched(i, bq, SQUARE_START);
      break;
    }
  }
}

void check_for_unmatched(int pos, struct balance_queue *bq, char check_for) {
  for (int save = pos; save >= 0; save--) {
    // zero this point and itself
    if (bq->queue[save][2] == check_for) {
      zero_el_queue(bq, save);
      zero_el_queue(bq, pos);
      break;
    }
  }
}
