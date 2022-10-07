#include "s21_string.h"

void *s21_to_lower(const char *str) {
    char *str_ret = calloc(s21_strlen(str) + 1, sizeof(char));

    if (str_ret) {
        int count = 0;
        while (str[count]) {
            if ((int)str[count] >= 'A' && (int)str[count] <= 'Z') {
                str_ret[count] = (int)str[count] + 32;
            } else {
                str_ret[count] = str[count];
            }
            count++;
        }
        str_ret[count] = '\0';
    }
    return str_ret;
}
