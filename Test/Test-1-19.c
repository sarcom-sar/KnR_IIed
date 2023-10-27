#include "../Unity/unity.h"
#include "../Src/1-19func.c"


void setUp (void) {}
void tearDown (void) {}

void test_reverse_line_normal(void) {
  char line_normal[] = "test\n";
  reverse_line(line_normal, 5);
  TEST_ASSERT_EQUAL_STRING("tset\n", line_normal);
}

void test_reverse_line_empty(void) {
  char line_empty[] = "\n";
  reverse_line(line_empty, 7);
  TEST_ASSERT_EQUAL_STRING("\n", line_empty);
}

int main(void) {
  UNITY_BEGIN();
  RUN_TEST(test_reverse_line_normal);
  RUN_TEST(test_reverse_line_empty);
  return UNITY_END();
}
