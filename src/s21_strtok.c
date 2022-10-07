#include "s21_string.h"

char *s21_strtok(char *str, const char *delim) {
    static char *str_parse = (char *) S21_NULL;
    char *res_ptr = (char *) S21_NULL;
    int parse_counter = 0;
    int yield_f = 0, token_f = 0;
    if (str) {
        str_parse = str;
    }
    res_ptr = str_parse;
    if (str_parse && str_parse[0] == '\0') {
        res_ptr = (char *) S21_NULL;
    }
    while (yield_f == 0 && str_parse && str_parse[parse_counter] != '\0') {
        if (s21_strchr(delim, str_parse[parse_counter])) {
            str_parse[parse_counter] = '\0';
            token_f = 1;
        } else if (token_f == 1) {
            yield_f = 1;
            str_parse = &str_parse[parse_counter];
        }
        parse_counter++;
    }
    if (yield_f == 0 && str_parse && str_parse[parse_counter] == '\0') {
        str_parse = (char *) S21_NULL;
    }
    return res_ptr;
}
