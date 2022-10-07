#include "s21_string.h"

s21_size_t  s21_strcspn(const char *str1, const char *str2) {
    const char  *min;
    const char  *temp;
    char flag;
    min = (const char *)__LONG_MAX__;
    while (*str2 != '\0') {
        temp = s21_strchr(str1, *str2);
        if (temp != S21_NULL && temp < min)
            min = temp;
        str2++;
    }
    if (min == (const char *)__LONG_MAX__)
        flag = s21_strlen(str1);
    else
        flag = min - str1;
    return flag;
}
