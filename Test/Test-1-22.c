#include "../Unity/unity.h"
#include "../Src/1-22func.c"


void setUp (void) {}
void tearDown (void) {}

void test_break_line_normal(void) {
  char line_normal[] = "Lorem ipsum dolor sit amet, consectetuer adipiscing elit. Donec hendrerit tempor tellus. Donec pretium posuere tellus. Proin quam nisl, tincidunt et, mattis\n";
  break_line(line_normal);
  TEST_ASSERT_EQUAL_STRING("Lorem ipsum dolor sit amet, consectetuer adipiscing elit.Donec hendrerit tempor\ntellus.Donec pretium posuere tellus.Proin quam nisl, tincidunt et, mattis\n", line_normal);
}

int main(void) {
  UNITY_BEGIN();
  RUN_TEST(test_break_line_normal);
  return UNITY_END();
}
