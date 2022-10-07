#include "s21_string.h"

char* s21_strcat(char*dest , const char* src) {
    char * ret = dest;
    while (*dest != '\0') {
        dest++;
    }
    while ((*dest = *src)) {
        dest++;
        src++;
    }
    return ret;
}
