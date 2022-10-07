#include "s21_string.h"

void *s21_memmove(void *dest, const void *src, s21_size_t n) {
    char *dest1 = dest;
    const char *src1 = src;
    s21_size_t i;
    if (src1 >= dest1) {
        for (i = 0; i < n; i++) {
            dest1[i] = src1[i];
        }
    } else {
        for (i = n; i > 0; i--) {
            dest1[i-1] = src1[i-1];
        }
    }
    return dest1;
}

