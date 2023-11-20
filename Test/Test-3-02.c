#include "../Src/3-02func.c"
#include "../Unity/unity.h"

void setUp(void) {}
void tearDown(void) {}

void test_escape_normal(void) {
  char escape_t[1024] = "a\t\nb";
  char escape_s[1024];
  escape(escape_s, escape_t);
  TEST_ASSERT_EQUAL_STRING("a\\t\\nb", escape_s);
}

void test_unescape_normal(void) {
  char escape_t[1024] = "a\\t\\nb";
  char escape_s[1024];
  unescape(escape_s, escape_t);
  TEST_ASSERT_EQUAL_STRING("a\t\nb", escape_s);
}

int main(void) {
  UNITY_BEGIN();
  RUN_TEST(test_escape_normal);
  RUN_TEST(test_unescape_normal);
  return UNITY_END();
}
