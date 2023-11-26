#include "../Src/1-24func.c"
#include "../Unity/unity.h"

void setUp(void) {}
void tearDown(void) {}

void test_init_balance_queue(void) {
  struct balance_queue balque;
  init_balance_queue(&balque);
  TEST_ASSERT_EQUAL_INT(1000, balque.last_point);
  for (int i = 0; i < 1000; i++) {
    TEST_ASSERT_EQUAL_INT(0, balque.queue[i][0]);
    TEST_ASSERT_EQUAL_INT(0, balque.queue[i][1]);
    TEST_ASSERT_EQUAL_INT(0, balque.queue[i][2]);
  }
}

void test_init_balance_state(void) {
  struct balance_state balstat;
  init_balance_state(&balstat);
  TEST_ASSERT_EQUAL_INT(0, balstat.curr_line);
  TEST_ASSERT_EQUAL_INT(0, balstat.is_escape);
  TEST_ASSERT_EQUAL_INT(0, balstat.is_in_quote);
  TEST_ASSERT_EQUAL_INT(0, balstat.queue_point);
}

void test_queue_add(void) {
  struct balance_queue balque;
  init_balance_queue(&balque);

  struct balance_state balstat;
  init_balance_state(&balstat);

  TEST_ASSERT_EQUAL_INT(1, queue_add('(', 5, &balque, &balstat));
  TEST_ASSERT_EQUAL_INT(0, balque.queue[0][0]);
  TEST_ASSERT_EQUAL_INT(5, balque.queue[0][1]);
  TEST_ASSERT_EQUAL_INT('(', balque.queue[0][2]);
}

void test_zero_el_queue(void) {
  struct balance_queue balque;
  init_balance_queue(&balque);

  balque.queue[5][0] = 5;
  balque.queue[5][1] = 25;
  balque.queue[5][2] = ')';

  zero_el_queue(&balque, 5);

  TEST_ASSERT_EQUAL_INT(0, balque.queue[5][0]);
  TEST_ASSERT_EQUAL_INT(0, balque.queue[5][1]);
  TEST_ASSERT_EQUAL_INT(0, balque.queue[5][2]);
}

void test_check_balance(void) {
  struct balance_queue balque;
  init_balance_queue(&balque);

  struct balance_state balstat;
  init_balance_state(&balstat);

  check_balance("(a)[\"]\"{}", &balque, &balstat);

  TEST_ASSERT_EQUAL_INT(0, balque.queue[0][0]);
  TEST_ASSERT_EQUAL_INT(0, balque.queue[0][1]);
  TEST_ASSERT_EQUAL_INT('(', balque.queue[0][2]);

  TEST_ASSERT_EQUAL_INT(0, balque.queue[1][0]);
  TEST_ASSERT_EQUAL_INT(2, balque.queue[1][1]);
  TEST_ASSERT_EQUAL_INT(')', balque.queue[1][2]);

  TEST_ASSERT_EQUAL_INT(0, balque.queue[2][0]);
  TEST_ASSERT_EQUAL_INT(3, balque.queue[2][1]);
  TEST_ASSERT_EQUAL_INT('[', balque.queue[2][2]);

  TEST_ASSERT_EQUAL_INT(0, balque.queue[3][0]);
  TEST_ASSERT_EQUAL_INT(7, balque.queue[3][1]);
  TEST_ASSERT_EQUAL_INT('{', balque.queue[3][2]);

  TEST_ASSERT_EQUAL_INT(0, balque.queue[4][0]);
  TEST_ASSERT_EQUAL_INT(8, balque.queue[4][1]);
  TEST_ASSERT_EQUAL_INT('}', balque.queue[4][2]);
}

void test_check_for_unmached(void) {
  struct balance_queue balque;
  init_balance_queue(&balque);

  struct balance_state balstat;
  init_balance_state(&balstat);

  balque.queue[5][0] = 5;
  balque.queue[5][1] = 5;
  balque.queue[5][2] = ')';
  balque.queue[0][0] = 0;
  balque.queue[0][1] = 0;
  balque.queue[0][2] = '(';

  check_for_unmatched(5, &balque, '(');

  TEST_ASSERT_EQUAL_INT(0, balque.queue[5][0]);
  TEST_ASSERT_EQUAL_INT(0, balque.queue[5][1]);
  TEST_ASSERT_EQUAL_INT(0, balque.queue[5][2]);

  TEST_ASSERT_EQUAL_INT(0, balque.queue[0][0]);
  TEST_ASSERT_EQUAL_INT(0, balque.queue[0][1]);
  TEST_ASSERT_EQUAL_INT(0, balque.queue[0][2]);
}

int main(void) {
  UNITY_BEGIN();
  RUN_TEST(test_init_balance_queue);
  RUN_TEST(test_init_balance_state);
  RUN_TEST(test_queue_add);
  RUN_TEST(test_zero_el_queue);
  RUN_TEST(test_check_balance);
  RUN_TEST(test_check_for_unmached);
  return UNITY_END();
}
