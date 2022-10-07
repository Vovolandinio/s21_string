#include "s21_string.h"

void s21_itoa(int num, char *str) {
    int pow = 1;
    int j = 0;
    if (num < 0) {
        num = abs(num);
        j = num;
        while (j >= 10) {
            pow = pow * 10;
            j /= 10;
        }
        *str++ = '-';
        while (pow > 0) {
            *str++ = 48 + num / pow;
            num %= pow;
            pow /= 10;
        }
        *str = '\0';
    } else {
        j = num;
        while (j >= 10) {
            pow *= 10;
            j /= 10;
        }
        while (pow > 0) {
            *str++ = 48 + num / pow;
            num %= pow;
            pow /= 10;
        }
        *str = '\0';
    }
}


char *s21_strerror(int errnum) {
    char* arroferrors[] = _ERRORS_LIST_;
    char* retstr = "";
    char error[4096] = {'\0'};
    char stt[10];
    #if defined __APPLE__
    if (errnum < 0 || errnum > _ERRORS_MAX_) {
    s21_itoa(errnum, stt);
    s21_strcpy(error, "Unknown error: ");
    retstr = s21_strncat(error, stt, s21_strlen(error));
    } else {
    retstr = arroferrors[errnum];
    }
    #elif defined __linux__
    if (errnum < 0 || errnum > _ERRORS_MAX_) {
    s21_itoa(errnum, stt);
    s21_strcpy(error, "Unknown error ");
    retstr = s21_strncat(error, stt, s21_strlen(error));
    } else {
    retstr = arroferrors[errnum];
    }
    #endif
    return retstr;
}
