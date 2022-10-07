#include "s21_string.h"

char *s21_strrchr(const char *str, int c) {
    int counter = 0;
    int rchar_offset = -1;
    char *rchar_pointer = (char *)S21_NULL;
    while (str[counter] != '\0') {
        while (str[counter] != '\0' && str[counter] != c) {
            counter++;
        }
        if (str[counter] != '\0') {
            rchar_offset = counter;
            counter++;
        }
    }
    if (c == '\0') {
        rchar_offset = counter;
    }
    if (rchar_offset != -1) {
        rchar_pointer = (char *)(str + rchar_offset);
    }
    return rchar_pointer;
}
