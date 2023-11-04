#include "../Unity/unity.h"
#include "../Src/1-24func.c"


void setUp (void) {}
void tearDown (void) {}

void test_is_two_balanced_normal(void) {
  char line[] = "()){{{}}}\n";
  int empty = 0;
  TEST_ASSERT_EQUAL_INT(-1, is_two_balanced(line, "()", &empty));
  empty = 0;
  TEST_ASSERT_EQUAL_INT(0, is_two_balanced(line, "{}", &empty));
}

void test_is_one_balanced_normal(void) {
  char line[] = "\"\"\'\'\\\"\n";
  int empty = 0;
  TEST_ASSERT_EQUAL_INT(0, is_one_balanced(line, '\"', &empty));
  empty = 0;
  TEST_ASSERT_EQUAL_INT(0, is_one_balanced(line, '\'', &empty));
}

void test_is_two_balanced_weird(void) {
  char line[] = "\\\(\\\)) \\\{\\\}{\n";
  int empty = 0;
  TEST_ASSERT_EQUAL_INT(-1, is_two_balanced(line, "()", &empty));
  empty = 0;
  TEST_ASSERT_EQUAL_INT(1, is_two_balanced(line, "{}", &empty));
}

void test_is_one_balanced_weird(void) {
  char line[] = "\"\\\"\" \'\\\'\'\n";
  int empty = 0;
  TEST_ASSERT_EQUAL_INT(0, is_one_balanced(line, '\"', &empty));
  empty = 0;
  TEST_ASSERT_EQUAL_INT(0, is_one_balanced(line, '\'', &empty));
}

int main(void) {
  UNITY_BEGIN();
  RUN_TEST(test_is_two_balanced_normal);
  RUN_TEST(test_is_one_balanced_normal);
  RUN_TEST(test_is_two_balanced_weird);
  RUN_TEST(test_is_one_balanced_weird);
  return UNITY_END();
}
