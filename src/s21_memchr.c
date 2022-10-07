#include "s21_string.h"

void    *s21_memchr(const void *str, int sym, s21_size_t n) {
    char *str2 = (char *)str;
    void *return1  = S21_NULL;

    while (*str2 != sym && n > 1) {
        str2 += 1;
        n -= 1;
    }
    if (*str2 == sym) {
        return1 = (void *)str2;
    }
    return(return1);
}
