#include "s21_string.h"

int s21_memcmp(const void *str1, const void *str2, s21_size_t n) {
    unsigned char *s1 = (unsigned char *)str1;
    unsigned char *s2 = (unsigned char *)str2;
    int res = 0;
    int exit = 0;

    while (exit == 0 && n > 0) {
        if (*s1 != *s2) {
            res = *s1 - *s2;
            exit = 1;
        }
        s1++;
        s2++;
        n--;
    }

    return res;
}
