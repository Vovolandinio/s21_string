#include "s21_string.h"

char *s21_strcpy(char *dest, const char *src) {
    char *ret_str = dest;

    while ((*dest++ = *src++) != '\0') {}

    return ret_str;
}
