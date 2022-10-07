#include "s21_string.h"

void* s21_memset(void* b, int c, s21_size_t len) {
    char* p = (char*)b;
    for (s21_size_t i = 0; i != len; ++i) {
        p[i] = c;
    }
    return b;
}
