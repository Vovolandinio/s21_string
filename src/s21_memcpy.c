#include "s21_string.h"

void *s21_memcpy(void *dest, const void *src, s21_size_t n) {
    char *a = (char*)dest;
    const char *b = (const char*)src;
    void *return1 = dest;
    if (a != S21_NULL && b != 0) {
        while (n--) {
            *a++ = *b++;
        }
    }
    return return1;
}
