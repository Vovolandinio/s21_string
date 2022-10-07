#include "s21_string.h"

size_t s21_strspn(const char *str1, const char *str2) {
    s21_size_t string_counter = 0;
    s21_size_t sample_counter = 0;
    int exit_f = 0;
    int yield_f = 0;
    if (str1[0] == '\0' || str2[0] == '\0') {
        exit_f = 1;
    }
    while (str1[string_counter] != '\0' && exit_f == 0) {
        while (yield_f == 0) {
            if (str1[string_counter] == str2[sample_counter]) {
                yield_f = 1;
            }
            if (str2[sample_counter] == '\0') {
                exit_f = 1;
            }
            sample_counter++;
        }
        if (exit_f == 0) {
            string_counter++;
        }
        sample_counter = 0;
        yield_f = 0;
    }
    return string_counter;
}
