#include "../Unity/unity.h"
#include "../Src/1-22func.c"


void setUp (void) {}
void tearDown (void) {}

void test_break_line_normal(void) {
  char line_normal[] = "Lorem ipsum dolor sit amet, consectetuer adipiscing elit. Donec hendrerit tempor tellus. Donec pretium posuere tellus. Proin quam nisl, tincidunt et, mattis\n";
  break_line(line_normal);
  TEST_ASSERT_EQUAL_STRING("Lorem ipsum dolor sit amet, consectetuer adipiscing elit. Donec hendrerit tempor\ntellus. Donec pretium posuere tellus. Proin quam nisl, tincidunt et, mattis\n", line_normal);
}

void test_break_line_too_short(void) {
  char line_too_short[] = "A word\n";
  break_line(line_too_short);
  TEST_ASSERT_EQUAL_STRING("A word\n", line_too_short);
}

void test_break_line_long_word(void) {
  char line_long_word[] =
      "Aliquameratvolutpat. Nunceleifendleovitaemagna. "
      "Inideratnonorcicommodolobortis. "
      "Proinnequemassa,cursusut,gravidaut,lobortiseget,lacus. Seddiam. "
      "Praesentfermentumtemportellus. Nullamtempus. "
      "Maurisacfelisvelvelittristiqueimperdiet. Donecatpede. "
      "Etiamvelnequenecduidignissimbibendum. Vivamusidenim. "
      "Phasellusnequeorci,portaa,aliquetquis,sempera,massa. Phaselluspurus. "
      "Pellentesquetristiqueimperdiettortor. Nameuismodtellusiderat.\n";
  break_line(line_long_word);
  TEST_ASSERT_EQUAL_STRING("Aliquameratvolutpat. Nunceleifendleovitaemagna. Inideratnonorcicommodolobortis.\nProinnequemassa,cursusut,gravidaut,lobortiseget,lacus. Seddiam.\nPraesentfermentumtemportellus. Nullamtempus. Maurisacfelisvelvelittristiqueimperdiet. Donecatpede.\nEtiamvelnequenecduidignissimbibendum. Vivamusidenim.\nPhasellusnequeorci,portaa,aliquetquis,sempera,massa. Phaselluspurus. Pellentesquetristiqueimperdiettortor.\nNameuismodtellusiderat.\n", line_long_word);
}

int main(void) {
  UNITY_BEGIN();
  RUN_TEST(test_break_line_normal);
  RUN_TEST(test_break_line_too_short);
  RUN_TEST(test_break_line_long_word);
  return UNITY_END();
}
