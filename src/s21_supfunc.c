#include "s21_string.h"

int s21_is_number(int character) {
    if (character >= 48 && character <= 57)
        return (1);
    else
        return (0);
}

char *s21_strdup(const char *s1) {
    char *s2;
    s21_size_t len;
    s21_size_t i;

    len = s21_strlen(s1);
    if (!(s2 = (char *)calloc(len + 1, sizeof(char)))) return (S21_NULL);
    i = 0;
    while (s1[i]) {
        s2[i] = s1[i];
        i += 1;
    }
    s2[i] = '\0';
    return (s2);
}

int extra_is_spec(char c, struct s_format *code_params) {
    int i = 0;
    if (c == 'd' || c == 'i' || c == 'c' || c == 'f' || c == 's' || c == 'u' ||
        c == '%') {
        i = 1;
    }
    code_params->spec = (c == 'u' ? 1 : 0);
    return i;
}

// Инициализатор структуры
void extra_init_struct(struct s_format *code_params) {
    code_params->isInt = 0;
    code_params->flagPlus = 0;
    code_params->flagMinus = 0;
    code_params->flagSpace = 0;
    code_params->width = 0;
    code_params->widthMustBeWrittenByZero = 0;
    code_params->widthZeroDetected = 0;
    code_params->precision = 0;
    code_params->precisionWillBeSpecified = 0;
    code_params->length_h = 0;
    code_params->length_l = 0;
    code_params->isAsteriskWidth = 0;
    code_params->isAsteriskFloatWidthDescription = 0;
    code_params->precisionIsNull = 0;
    code_params->precisionSetByZero = 0;
    code_params->isLongDouble = 0;
    code_params->spec = 0;
}

// Записывает символ в буффер
void extra_write_char(const char **format, char **str,
                      struct s_format *code_params, char c) {
    if (code_params->flagMinus) {
        **str = c;
        (*str)++;
    }
    for (int i = 0; i < code_params->width - 1; i++) {
        **str = ' ';
        (*str)++;
    }
    if (!code_params->flagMinus) {
        **str = c;
        (*str)++;
    }
    (*format)++;
}

// Записывает знак процента в буффер
void extra_write_percent(const char **format, char **str) {
    **str = '%';
    (*str)++;
    (*format)++;
}

// Заполняет строку размером n терминаторами.
void extra_b_zero(void *s, s21_size_t n) {
    s21_size_t i;

    i = 0;
    while (i < n) {
        ((char *)s)[i] = 0;
        i++;
    }
}

// Выделяет память для чего-либо
void *extra_memalloc(s21_size_t size) {
    void *some;

    some = calloc(size, 1);
    if (!some) return (S21_NULL);
    extra_b_zero(some, size);
    return (some);
}

// Конвертирует интеджер в строку
char *extra_itoa(long int n) {
    long int tmpn;
    int len;
    int neg;
    char *str;

    tmpn = n;
    len = 2;
    neg = tmpn < 0 ? 1 : 0;

    while (tmpn /= 10) len++;
    if (!(str = extra_memalloc(BUFFSIZE))) return (S21_NULL);
    len += neg;
    str[--len] = '\0';
    if (neg) n *= -1;
    while (len--) {
        str[len] = n % 10 + '0';
        n = n / 10;
    }
    if (neg) str[0] = '-';
    return (str);
}

char *extra_utoa(unsigned long long int n) {
    unsigned long long int tmpn;
    int len;
    char *str;

    tmpn = n;
    len = 2;

    while (tmpn /= 10) len++;
    if (!(str = extra_memalloc(BUFFSIZE))) return (S21_NULL);
    str[--len] = '\0';
    while (len--) {
        str[len] = n % 10 + '0';
        n = n / 10;
    }
    return (str);
}

char *extra_ldtoa(long long int n) {
    long long int tmpn;
    int len;
    int neg;
    char *str;

    tmpn = n;
    len = 2;
    neg = tmpn < 0 ? 1 : 0;
    int min = 0;

    while (tmpn /= 10) len++;
    if (!(str = extra_memalloc(BUFFSIZE))) return (S21_NULL);
    len += neg;
    str[--len] = '\0';
    if (neg) {
        if (n == LONG_MIN) {
            n += 1;
            n = n * (-1);
            min = 1;
        } else {
            n *= -1;
        }
    }
    while (len--) {
        str[len] = n % 10 + '0';
        n = n / 10;
    }
    char *tmpns = str;
    if (min) {
        while (*(tmpns++) != '\0') {
            tmpns--;
            tmpns--;
            *tmpns += 1;
        }
    }
    if (neg)
        str[0] = '-';
    return (str);
}

char *check_float_max_min_cases(long double f_case, char *str) {
    if (f_case == INFINITY) return (s21_strdup("inf"));
    if (f_case == -INFINITY) return (s21_strdup("-inf"));
    if (f_case == NAN) return (s21_strdup("nan"));
    if (f_case == DBL_MAX || f_case == FLT_MAX)
        extra_float_max_conversion(str);
    else
        free(str);
    char *s;
    s = extra_str_new(2);
    return (s);
}

long double s21_round(int accuracy, long double number) {
    if (accuracy == 0) {
        accuracy = 6;
    }
    long double n = number;
    int min_check = 0;
    if (n < 0) {
        min_check = 1;
        n *= -1;
    }
    double c;
    double m = modf(n, &c) * pow(10.0, accuracy);
    double mod = fmod(m, pow(10.0, accuracy));
    if (mod == 50) {
        m = round(m + 1) / pow(10.0, accuracy);
    } else {
        m = round(m) / pow(10.0, accuracy);
    }
    n = c + m;
    if (min_check == 1) {
        n *= -1;
    }
    return n;
}


// Конвертирует флоат в строку
char *extra_ftoa(long double f, struct s_format code_params) {
    int i;
    double fpNumber;
    int size;
    char *str = "";
    int isNegative;

    i = 0;
    size = 1;

    fpNumber = f;
    isNegative = fpNumber < 0 ? 1 : 0;

    fpNumber = s21_round(code_params.precision, fpNumber);

    if (fpNumber == INFINITY || fpNumber == -INFINITY || fpNumber == DBL_MAX ||
        fpNumber == FLT_MAX || fpNumber == NAN) {
        check_float_max_min_cases(fpNumber, str);
    }
    if (fpNumber < 0) isNegative = 1;
    if (isNegative) fpNumber *= -1;
    char *lenNum = (extra_itoa(fpNumber));

    size += (s21_strlen(lenNum) + isNegative);
    free(lenNum);
    size += code_params.precision <= 0 ? 6 : code_params.precision;
    size = size < 0 ? 6 : size;
    str = extra_str_new(size + 4);

    if (isNegative == 1) str[i++] = '-';

    extra_convert_integer(&fpNumber, &str, &i,
                          (extra_find_multiplier(fpNumber, &size)));

    if ((code_params.precision == 0 &&
         code_params.precisionWillBeSpecified == 1) ||
        code_params.precisionIsNull) {
        extra_cut_str(str, code_params.precision, 1);
        return (str);
    }
    extra_convert_decimal(&str, &i, (float)fpNumber, size);
    extra_cut_str(str, code_params.precision, 0);
    return (str);
}

// Конвертирует максимальный флоат
char *extra_float_max_conversion(char *str) {
    int i;
    char float_max[50];

    i = 0;
    s21_strcpy(float_max, "340282346638528859811704183484516925440.000000\0");
    if (!(str = (char *)malloc(sizeof(float_max)))) return (S21_NULL);
    while (float_max[i] != '\0') {
        str[i] = float_max[i];
        i++;
    }
    return (str);
}
// Ищет множитель для работы с десятичной частью
long long int extra_find_multiplier(long double fpNumber, int *size) {
    long int multiplier;
    long int extra;

    extra = (long int)(fpNumber);
    multiplier = 1;
    while ((extra /= 10) != 0) {
        multiplier *= 10;
        size++;
    }
    return (multiplier);
}

// Конвертирует десятичную часть дабла
void extra_convert_decimal(char **str, int *i, float fpNumber, int accuracy) {
    int j;
    char *s;

    fpNumber *= 10;
    j = 0;
    s = *str;
    s[(*i)++] = '.';
    while (j++ < accuracy) {
        long int tmp = ((long int)fpNumber != 9) ? (long int)(fpNumber + 0.01)
                                        : (long int)fpNumber;
        s[(*i)++] = (char)(tmp + 48);
        fpNumber = (fpNumber - tmp) * 10;
    }
}

// Конвертирует целую часть дабла
void extra_convert_integer(double *fpNumber, char **str, int *i,
                           long int multiplier) {
    char *s;
    long int b;

    b = (long int)*fpNumber;
    s = *str;
    if (b < 0) {
        *fpNumber *= -1;
        b *= -1;
    }
    if (b == 0) {
        s[(*i)++] = '0';
        return;
    }
    *fpNumber -= (long double)b;
    while (multiplier >= 1) {
        s[(*i)++] = (char)((b / multiplier) + 48);
        b = b - (b / multiplier) * multiplier;
        multiplier /= 10;
    }
}

// Режет строку согласно необходимой точности
void extra_cut_str(char *str, int pres, int isSetByZero) {
    int i;
    int k;

    i = 0;
    if (isSetByZero) {
        k = 0;
    } else {
        k = pres <= 0 ? 6 : pres;
        while (str[i] != '.') str++;
    }

    while (k != 0 && (*str != '\0')) {
        str++;
        k--;
    }

    if (isSetByZero == 1) {
        s21_size_t j = s21_strlen(str);
        str[j] = '\0';
    } else {
        *(++str) = '\0';
    }
}

// Создает новую строку
char *extra_str_new(s21_size_t size) {
    char *str;
    if (size + 1 < size) return (S21_NULL);
    str = (char *)calloc(BUFFSIZE, sizeof(char));
    if (str == 0) return (S21_NULL);
    extra_b_zero(str, size + 1);
    return (str);
}

// Возвращает длину предполагаемой строки исходя из количество цифр в числе
int extra_count_numerals(long double chislo) {
    char *str;
    int k;

    str = extra_itoa((long long int)chislo);
    k = s21_strlen(str);
    free(str);

    return (k);
}

// Конвертирует дабл
char *extra_dtoa(long double ldNumber, struct s_format code_params) {
    int i;
    long double chislo;
    int size;
    char *str;
    int sign;

    i = 0;
    size = 1;

    chislo = ldNumber;

    sign = 0;
    if (chislo < 0) sign = 1;

    size += code_params.precision <= 0 ? 6 : code_params.precision;
    size += (sign);
    str = extra_str_new(extra_count_numerals(chislo) + 1);
    if (sign == 1) str[i++] = '-';
    extra_convert_dbl_integer(&chislo, &str, &i,
                             (extra_find_multiplier(chislo, &size)));
    if (code_params.precision == 0 &&
        code_params.precisionWillBeSpecified == 1) {
        extra_cut_str(str, code_params.precision,
                      code_params.precisionSetByZero);
        return (str);
    }
    extra_convert_dbl_decimal(&str, &i, chislo,
                             (extra_count_numerals(chislo) + size + 4 + sign));
    str = extra_round(str, code_params.precision,
                       code_params.precisionSetByZero);
    extra_cut_str(str, code_params.precision, code_params.precisionSetByZero);
    str[i - 1] = '\0';
    return (str);
}

// Конвертирует целую часть дабла
void extra_convert_dbl_decimal(char **str, int *i, long double chislo,
                              int accuracy) {
    int j;
    char *s;

    chislo *= 10;
    j = 0;
    s = *str;
    s[(*i)++] = '.';
    while (j++ < accuracy) {
        long long int tmp = ((long long int)chislo != 9) ? (long long int)(chislo + 0.01)
                                           : (long long int)chislo;
        s[(*i)++] = (char)(tmp + 48);
        chislo = (chislo - tmp) * 10;
    }
}

// Конвертирует десятичную часть дабла
void extra_convert_dbl_integer(long double *ldblNumber, char **str, int *i, long int multiplier) {
    char *s;
    long int b;

    b = (long int)*ldblNumber;
    s = *str;
    if (b < 0) {
        *ldblNumber *= -1;
        b *= -1;
    }
    if (b == 0) s[(*i)++] = '0';
    *ldblNumber -= (long double)b;
    while (multiplier >= 1) {
        s[(*i)++] = (char)((b / multiplier) + 48);
        b = b - (b / multiplier) * multiplier;
        multiplier /= 10;
    }
}

int extra_recursion(int *i, char *str) {
    if (*str == '.' && *(++str) == '0') {
        return 1;
    }
    if (*str == '9' && *(str--) != '.') {
        str++;
        *str = '0';
        str--;
        int rounded = extra_recursion(i, str);
        if (rounded) return (1);
    } else if (*str != '0' && *(str--) != '.') {
        *str += 1;
    } else if (*str != '0' && *(str--) == '.') {
        *str += 1;
        return 1;
    }
    return (0);
}

// Округлятор последней цифры
char *extra_round(char *str, int accuracy, int precisionSetByZero) {
    int i = 0;

    char *tmp = str;
    while (*str != '.') {
        str++;
    }
    str++;
    if (accuracy == 0 && precisionSetByZero) {
        accuracy = 0;
    } else if (accuracy == 0) {
        accuracy = 6;
    }
    i += accuracy + 1;
    for (int k = 0; k < i; k++) {
        str++;
    }

int k = 0;
if (*str >= 5 && *(str--) != '.') {
    int rounded = extra_recursion(&i, str);
    k = rounded;
}

char *tmpn = tmp;

if (k) {
    while (*(tmp++) != '.') {
        tmp--;
        tmp--;
        *tmp += 1;
    }
}
    return (tmpn);
}

void handle_prec(char *buff, struct s_format *code_params) {
    char tmp[BUFFSIZE] = {'\0'};
    int isNeg = 0;
    int len = (int)s21_strlen(buff);

    if (buff[0] == '-') {
        tmp[0] = '-';
        len--;
        isNeg = 1;
    }

    if (code_params->precision > len) {
        int i;
        for (i = isNeg; i < code_params->precision - len + isNeg; i++)
            tmp[i] = '0';

        for (int j = isNeg; buff[j]; i++, j++) tmp[i] = buff[j];

        s21_strcpy(buff, tmp);
    }
    if (code_params->precisionWillBeSpecified &&
        code_params->precision == 0 && code_params->isInt && buff[0] == '0')
        buff[0] = '\0';
}

void handle_flags(char *buff, struct s_format *code_params) {
    char tmp[BUFFSIZE + 1] = {'\0'};
    if (code_params->flagPlus && !code_params->spec) {
        tmp[0] = buff[0] == '-' ? buff[0] : '+';
        s21_strcpy(tmp + 1, buff[0] == '-' ? buff + 1 : buff);
        s21_strcpy(buff, tmp);
    } else if (code_params->flagSpace && buff[0] != '-' &&
               code_params->spec != 1) {
        tmp[0] = ' ';
        s21_strcpy(tmp + 1, buff);
        s21_strcpy(buff, tmp);
    }
    if (code_params->width > (int)s21_strlen(buff)) {
        int i = code_params->width - s21_strlen(buff);
        if (!code_params->flagMinus) {
            s21_memset(tmp, code_params->widthMustBeWrittenByZero ? '0' : ' ',
                       i);
            if (buff[0] == '-' && code_params->widthMustBeWrittenByZero) {
                buff++;
            }
            s21_strcpy(tmp + i, buff);
        } else {
            s21_strcpy(tmp, buff);
            s21_memset(tmp + s21_strlen(tmp), ' ', i);
        }
        s21_strcpy(buff, tmp);
    }
}

void write_int(char *buff, struct s_format *code_params, char *string) {
    s21_memcpy(buff, string, s21_strlen(string));
    handle_prec(buff, code_params);
    handle_flags(buff, code_params);
}

void handle_string(struct s_format *code_params, char *buff, char *str) {
    char tmp[BUFFSIZE] = {'\0'};
    s21_strcpy(tmp, str);
    if (code_params->precisionWillBeSpecified)
        tmp[code_params->precision] = '\0';

    int shift = code_params->width - s21_strlen(tmp);
    s21_size_t len = s21_strlen(tmp);
    if (code_params->precisionIsNull) s21_memset(tmp, ' ', len);
    if (code_params->flagMinus && shift > 0) {
        s21_strcpy(buff, tmp);
        s21_memset(buff + len, ' ', shift);
    } else if (shift > 0) {
        s21_memset(buff, ' ', shift);
        s21_strcpy(buff + shift, tmp);
    } else {
        s21_strcpy(buff, tmp);
    }
}

void handle_wide_string(struct s_format *code_params, char *buff, wchar_t *wstr) {
    char tmp[BUFFSIZE] = {'\0'};
    char str[BUFFSIZE] = {'\0'};

    wcstombs(str, wstr, BUFFSIZE);
    s21_strcpy(tmp, str);
    if (code_params->precisionWillBeSpecified)
        tmp[code_params->precision] = '\0';

    int shift = code_params->width - s21_strlen(tmp);
    int len = s21_strlen(tmp);

    if (code_params->flagMinus && shift > 0) {
        s21_strcpy(buff, tmp);
        s21_memset(buff + len, ' ', shift);
    } else if (shift > 0) {
        s21_memset(buff, ' ', shift);
        s21_strcpy(buff + shift, tmp);
    } else {
        s21_strcpy(buff, tmp);
    }
}

void write_float(char *buff, struct s_format *code_params, char *string) {
    s21_memcpy(buff, string, s21_strlen(string));
    handle_flags(buff, code_params);
}

int parser(const char **inputLine, struct s_format *inputLineParams) {
    int flags = 0;

    while (**inputLine) {
        if (**inputLine == '-' || **inputLine == '+' || **inputLine == ' ') {
            if (**inputLine == '-')
                inputLineParams->flagMinus = 1;
            else if (**inputLine == '+')
                inputLineParams->flagPlus = 1;
            else if (**inputLine == ' ')
                inputLineParams->flagSpace = 1;
            (*inputLine)++;
        } else if (s21_is_number(**inputLine) == 1) {
            if (**inputLine == '0' && inputLineParams->widthZeroDetected == 0) {
                (*inputLine)--;
                if (s21_is_number(**inputLine) == 0) {
                    inputLineParams->widthMustBeWrittenByZero = 1;
                    inputLineParams->widthZeroDetected = 1;
                }
                (*inputLine)++;
            }
            inputLineParams->width =
                **inputLine - '0' + inputLineParams->width * 10;
            (*inputLine)++;
        } else if (**inputLine == '*') {
            (*inputLine)--;
            if (**inputLine != '.') {
                inputLineParams->isAsteriskWidth = 1;
                (*inputLine)++;
            } else {
                (*inputLine)++;
            }
            (*inputLine)++;
        } else if (**inputLine == '.') {
            (*inputLine)++;
            if ((!s21_is_number(**inputLine)) && **inputLine != '*')
                inputLineParams->precisionIsNull = 1;
            if (**inputLine == '*') {
                inputLineParams->isAsteriskFloatWidthDescription = 1;
                inputLineParams->precisionWillBeSpecified = 1;
            } else if (**inputLine == 'L' || **inputLine == 'f' ||
                       s21_is_number(**inputLine) == 1) {
                inputLineParams->precisionWillBeSpecified = 1;
            } else if (**inputLine == '0') {
                inputLineParams->precisionSetByZero = 1;
            }
            while (s21_is_number(**inputLine)) {
                inputLineParams->precision =
                    **inputLine - '0' + inputLineParams->precision * 10;
                (*inputLine)++;
            }
        } else if (**inputLine == 'h' || **inputLine == 'l' ||
                   **inputLine == 'L') {
            if (**inputLine == 'h')
                inputLineParams->length_h = 1;
            else if (**inputLine == 'l')
                inputLineParams->length_l = 1;
            else if (**inputLine == 'L')
                inputLineParams->isLongDouble = 1;
            (*inputLine)++;
        } else if (extra_is_spec(**inputLine, inputLineParams) == 1) {
            flags = 1;
            break;
        } else {
            flags = 0;
            break;
        }
    }
    return flags;
}

void extra_write_in_buff(const char **format, char **str,
                          struct s_format *code_params, va_list vlist,
                          char *buff) {
    if (**format == 'c') {
        if (code_params->isAsteriskWidth) {
            code_params->width = va_arg(vlist, int);
        }
        char c = va_arg(vlist, int);
        extra_write_char(format, str, code_params, c);
    } else if (**format == 'L') {
        code_params->isLongDouble = 1;
    } else if (**format == '%') {
        if (code_params->isAsteriskWidth) {
            code_params->width = va_arg(vlist, int);
        }
        extra_write_percent(format, str);
    } else if (**format == 's') {
        if (code_params->isAsteriskWidth) {
            code_params->width = va_arg(vlist, int);
        }
        if (code_params->isAsteriskFloatWidthDescription) {
            code_params->precision = va_arg(vlist, int);
        }
        if (code_params->length_l) {
            wchar_t *string = va_arg(vlist, wchar_t *);
            handle_wide_string(code_params, buff, string);
            (*format)++;
        } else {
            char *string = va_arg(vlist, char *);
            if (!string) string = "(null)";
            handle_string(code_params, buff, string);
            (*format)++;
        }
    } else if (**format == 'd' || **format == 'i') {
        code_params->isInt = 1;
        if (code_params->isAsteriskWidth)
            code_params->width = va_arg(vlist, int);
        if (code_params->isAsteriskFloatWidthDescription)
            code_params->precision = va_arg(vlist, int);
        if (code_params->length_l) {
            long long int lint = va_arg(vlist, long long int);
            if (lint < 0) code_params->flagPlus = 0;
            char *temps = extra_ldtoa(lint);
            write_int(buff, code_params, temps);
            free(temps);
            (*format)++;
        } else if (code_params->length_h) {
            short int sint = va_arg(vlist, int);
            if (sint < 0) code_params->flagPlus = 0;
            char *temp = extra_itoa(sint);
            write_int(buff, code_params, temp);
            free(temp);
            (*format)++;
        } else {
            int intParam = va_arg(vlist, int);
            if (intParam < 0) code_params->flagPlus = 0;
            char *tempr = extra_itoa(intParam);
            write_int(buff, code_params, tempr);
            free(tempr);
            (*format)++;
        }
    } else if (**format == 'f') {
        if (code_params->isAsteriskWidth)
            code_params->width = va_arg(vlist, int);
        if (code_params->isAsteriskFloatWidthDescription) {
            if (!code_params->precisionIsNull)
                code_params->precision = va_arg(vlist, int);
            else
                code_params->precision = 0;
        }
        if (code_params->isLongDouble) {
            long double floatParam = va_arg(vlist, long double);
            if (!floatParam) floatParam = 0;
            char *temporary = extra_dtoa(floatParam, *code_params);
            write_float(buff, code_params, temporary);
            free(temporary);
            (*format)++;
        } else {
            long double floatParam = va_arg(vlist, double);
            char *temporary = extra_ftoa(floatParam, *code_params);
            write_float(buff, code_params, temporary);
            free(temporary);
            (*format)++;
        }
    } else if (**format == 'u') {
        if (code_params->isAsteriskWidth)
            code_params->width = va_arg(vlist, int);
        if (code_params->isAsteriskFloatWidthDescription) {
            if (!code_params->precisionIsNull)
                code_params->precision = va_arg(vlist, int);
            else
                code_params->precision = 0;
        }
        long unsigned int uint = va_arg(vlist, long unsigned int);
        char *temp = extra_utoa(uint);
        write_int(buff, code_params, temp);
        free(temp);
        (*format)++;
    }
}

long long int s21_atoi(const char *str) {
    int i = 0;
    long long int res = 0;
    int sign = 1;
    while (str[i] == '0' || str[i] == ' ') i++;
    if (str[i] == '-') {
        sign = -1;
        i++;
    }
    while ('0' <= str[i] && str[i] <= '9') {
        res = res * 10 + ((int)str[i] - '0');
        i++;
    }
    return res * sign;
}
