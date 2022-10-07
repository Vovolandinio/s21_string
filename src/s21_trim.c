#include "s21_string.h"

void *s21_trim(const char *src, const char *trim_chars) {
  char *new_line = (char *)src;

  if (src == S21_NULL || trim_chars == S21_NULL) {
    new_line = S21_NULL;
  } else {
    s21_size_t len1 = s21_strlen(src);
    s21_size_t len2 = s21_strlen(trim_chars);

    s21_size_t first_number = 0;
    s21_size_t last_number;

    if (len1 <= 0)
      last_number = 0;
    else
      last_number = len1 - 1;

    for (s21_size_t i = 0; i < len1 - 1 && i == first_number; i++) {
      s21_size_t j = 0;
      for (; j < len2; j++) {
        if (src[i] == trim_chars[j]) {
          first_number = i + 1;
          break;
        }
      }
    }

    for (s21_size_t i = len1 - 1;
         i > 0 && i == last_number && last_number != first_number; i--) {
      s21_size_t j = 0;
      for (; j < len2; j++) {
        if (src[i] == trim_chars[j]) {
          last_number = i - 1;
          break;
        }
      }
    }

    if (first_number == last_number) {
      new_line = calloc((last_number - first_number + 1), sizeof(char));
      new_line[0] = '\0';

    } else {
      new_line = calloc((last_number - first_number + 2), sizeof(char));
      for (s21_size_t i = 0; i < (last_number - first_number + 1); i++) {
        new_line[i] = src[i + first_number];
      }
      new_line[last_number - first_number + 1] = '\0';
    }
  }
  return new_line;
}
