#include "s21_string.h"

int s21_strncmp(const char *str, const char *str2, s21_size_t n) {
  s21_size_t i;

  i = 0;
  if (n == 0) return (0);
  while (str[i] == str2[i] && str[i] != '\0' && i < n - 1) i++;
  return (((unsigned char *)str)[i] - ((unsigned char *)str2)[i]);
}
