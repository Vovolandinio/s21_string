#include "s21_string.h"

char *s21_strncpy(char *dest, const char *src, size_t n) {
    unsigned int i;
    i = 0;
    while (i < n && src[i]) {
        dest[i] = src[i];
        i++;
    }
    while (i < n) {
        dest[i] = '\0';
        i++;
    }
    return (dest);
}
