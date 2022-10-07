#include "s21_string.h"

int s21_sprintf(char *str, const char *format, ...) {
    va_list vlist;
    char *tmp = str;
    s21_size_t b = 0;
    va_start(vlist, format);

    while (*format) {
        if (*format != '%') {
            *str = *format;
            str++;
            format++;
        } else {
            struct s_format formatParams;
            extra_init_struct(&formatParams);
            format++;
            char buff[BUFFSIZE] = {'\0'};
            if (parser(&format, &formatParams) == 1) {
                extra_write_in_buff(&format, &str, &formatParams, vlist, buff);
            }
            for (int i = 0; buff[i]; i++, str++) {
                *str = buff[i];
                b += 1;
            }
        }
    }
    *str = '\0';
    b = s21_strlen(tmp);
    va_end(vlist);

    return (b);
}

