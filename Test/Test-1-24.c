#include "../Unity/unity.h"
#include "../Src/1-24func.c"


void setUp (void) {}
void tearDown (void) {}

void test_one_line_comment(void) {
  char line_normal[] = "one // word\n";
  int a = 0;
  trim_comments(line_normal, &a);
  TEST_ASSERT_EQUAL_STRING("one \n", line_normal);
}

void test_multi_one_line_comment(void) {
  char line[] = "a /*word*/b\n";
  int a = 0;
  trim_comments(line, &a);
  TEST_ASSERT_EQUAL_STRING("a b\n", line);
}

void test_multi_multi_line_comment(void) {
  char line[] = "a/* b c\n d e\n*/f g\n";
  int a = 0;
  trim_comments(line, &a);
  TEST_ASSERT_EQUAL_STRING("af g\n", line);
}

void test_escape_double_quotes(void) {
  char line[] = "printf(\"//noice/**/\");";
  int a = 0;
  trim_comments(line, &a);
  TEST_ASSERT_EQUAL_STRING("printf(\"//noice/**/\");", line);
}

void test_escape_single_quotes(void) {
  char line[] = "printf(\'///**/\');";
  int a = 0;
  trim_comments(line, &a);
  TEST_ASSERT_EQUAL_STRING("printf(\'///**/\');", line);
}

int main(void) {
  UNITY_BEGIN();
  RUN_TEST(test_one_line_comment);
  RUN_TEST(test_multi_one_line_comment);
  RUN_TEST(test_multi_multi_line_comment);
  RUN_TEST(test_escape_double_quotes);
  RUN_TEST(test_escape_single_quotes);
  return UNITY_END();
}
