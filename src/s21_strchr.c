#include "s21_string.h"

char* s21_strchr(const char* string, int character) {
    char* flag = S21_NULL;
    while (*string != character && *string != '\0') {
        string++;
    }
    if (*string == character) {
        flag = ((char*)string);
    } else {
        flag = S21_NULL;
    }
    return flag;
}
