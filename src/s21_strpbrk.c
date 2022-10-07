#include "s21_string.h"

char *s21_strpbrk(const char *str1, const char *str2) {
    int exit = 0;
    char *result = S21_NULL;
    s21_size_t i = 0;
     if (str1[0] == '\0' || str2[0] == '\0')
      exit = 1;
    while (*str1 != '\0' && exit != 1) {
         while (i < s21_strlen(str2)) {
            if (*str1 == *(str2 + i)) {
                exit = 1;
                result = (char *)str1;
            }
            i++;
        }
        str1++;
        i = 0;
    }
    return result;
}
