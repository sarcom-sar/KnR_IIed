#include "../Src/3-03func.c"
#include "../Unity/unity.h"

void setUp(void) {}
void tearDown(void) {}

void test_expand_forwards(void) {
  char expanded_basic[1024] = {0};
  expand("a-e", expanded_basic);
  TEST_ASSERT_EQUAL_STRING("abcde", expanded_basic);

  char expanded_twice[1024] = {0};
  expand("a-e0-9", expanded_twice);
  TEST_ASSERT_EQUAL_STRING("abcde0123456789", expanded_twice);

  char expanded_within[1024] = {0};
  expand("a-e-h", expanded_within);
  TEST_ASSERT_EQUAL_STRING("abcdefgh", expanded_within);

  char expanded_but_not_really[1024] = {0};
  expand("a-b", expanded_but_not_really);
  TEST_ASSERT_EQUAL_STRING("ab", expanded_but_not_really);
}

void test_expand_backwards(void) {
  char expanded_backwards[1024] = {0};
  expand("e-a", expanded_backwards);
  TEST_ASSERT_EQUAL_STRING("edcba", expanded_backwards);

  char expanded_twice_backwards[1024] = {0};
  expand("e-a9-0", expanded_twice_backwards);
  TEST_ASSERT_EQUAL_STRING("edcba9876543210", expanded_twice_backwards);

  char expanded_backwards_within[1024] = {0};
  expand("h-e-a", expanded_backwards_within);
  TEST_ASSERT_EQUAL_STRING("hgfedcba", expanded_backwards_within);

  char expanded_but_not_really[1024] = {0};
  expand("z-y", expanded_but_not_really);
  TEST_ASSERT_EQUAL_STRING("zy", expanded_but_not_really);
}

void test_expand_no_expansion(void) {
  char expanded_no_expansion[1024] = {0};
  expand("abe", expanded_no_expansion);
  TEST_ASSERT_EQUAL_STRING("abe", expanded_no_expansion);

  char expanded_nothing[1024] = {0};
  expand("", expanded_nothing);
  TEST_ASSERT_EQUAL_STRING("", expanded_nothing);
}

void test_expand_leading_trailing(void) {
  char expanded_leading[1024] = {0};
  expand("-a", expanded_leading);
  TEST_ASSERT_EQUAL_STRING("-a", expanded_leading);

  char expanded_trailing[1024] = {0};
  expand("a-", expanded_trailing);
  TEST_ASSERT_EQUAL_STRING("a-", expanded_trailing);
}

void test_expand_corner_case(void) {
  char expanded_newline[1024] = {0};
  expand("\n-a", expanded_newline);
  TEST_ASSERT_EQUAL_STRING("\n-a", expanded_newline);

  char expanded_hyphen[1024] = {0};
  expand("--a", expanded_hyphen);
  TEST_ASSERT_EQUAL_STRING("--a", expanded_hyphen);

  char expanded_alnum[1024] = {0};
  expand("A-8", expanded_alnum);
  TEST_ASSERT_EQUAL_STRING("A98", expanded_alnum);
}

void test_is_valid_char(void) {
  TEST_ASSERT_EQUAL_INT(0, is_valid_char('\n'));
  TEST_ASSERT_EQUAL_INT(0, is_valid_char('['));
  TEST_ASSERT_EQUAL_INT(1, is_valid_char('0'));
  TEST_ASSERT_EQUAL_INT(1, is_valid_char('9'));
  TEST_ASSERT_EQUAL_INT(1, is_valid_char('a'));
  TEST_ASSERT_EQUAL_INT(1, is_valid_char('A'));
  TEST_ASSERT_EQUAL_INT(1, is_valid_char('z'));
  TEST_ASSERT_EQUAL_INT(1, is_valid_char('Z'));
}

void test_len_between(void) {
  TEST_ASSERT_EQUAL_INT(0, len_between('a', 'a'));
  TEST_ASSERT_EQUAL_INT(1, len_between('b', 'a'));
  TEST_ASSERT_EQUAL_INT(-1, len_between('a', 'b'));
}

int main(void) {
  UNITY_BEGIN();
  RUN_TEST(test_is_valid_char);
  RUN_TEST(test_len_between);
  RUN_TEST(test_expand_forwards);
  RUN_TEST(test_expand_backwards);
  RUN_TEST(test_expand_no_expansion);
  RUN_TEST(test_expand_leading_trailing);
  RUN_TEST(test_expand_corner_case);
  return UNITY_END();
}
