#include "s21_string.h"

void *s21_insert(const char *src, const char *str, s21_size_t start_index) {
    char *str_ret = S21_NULL;
    if (src) {
        if (!str) {
            str = "";
        }
        s21_size_t after_del = start_index + s21_strlen(str);
        s21_size_t new_size = s21_strlen(str) + s21_strlen(src);
        if (start_index <= s21_strlen(src)) {
            str_ret = calloc((new_size + 1), sizeof(char));
        }
        if (str_ret && str) {
            for (s21_size_t count = 0; count < new_size; count++) {
                if (count < start_index) {
                    str_ret[count] = src[count];
                }

                if ((count >= start_index && count < after_del) && str[count - start_index] != '\0') {
                    str_ret[count] = str[count - start_index];
                }

                if (count >= after_del) {
                    str_ret[count] = src[count - after_del + start_index];
                }
            }
        }
    }

    return str_ret;
}
