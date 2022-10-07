#include "s21_string.h"

char *s21_strstr(const char *haystack, const char *needle) {
    size_t str_len = s21_strlen(haystack), needle_len = s21_strlen(needle);
    int hay_counter = 0;
    int exit_f = 0;
    char *res_ptr = (char *)S21_NULL;
    if (haystack[0] == '\0') {
        exit_f = 1;
    }
    if (needle[0] == '\0') {
        res_ptr = (char *) haystack;
        exit_f = 1;
    }
    while (needle_len <= str_len && exit_f == 0) {
        if (s21_memcmp(&haystack[hay_counter], needle, needle_len) == 0) {
            res_ptr = (char *) haystack + hay_counter;
            exit_f = 1;
        }
        str_len--;
        hay_counter++;
    }
    return res_ptr;
}
