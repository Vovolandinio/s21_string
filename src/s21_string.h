#ifndef SRC_S21_STRING_H_
#define SRC_S21_STRING_H_
#define _MAC_OS_

// Errors for MACOS
#ifdef __APPLE__
#define _ERRORS_MAX_ 106
#define _ERRORS_LIST_  {"Undefined error: 0", \
"Operation not permitted", \
"No such file or directory", \
"No such process", \
"Interrupted system call", \
"Input/output error", \
"Device not configured", \
"Argument list too long", \
"Exec format error", \
"Bad file descriptor", \
"No child processes", \
"Resource deadlock avoided", \
"Cannot allocate memory", \
"Permission denied", \
"Bad address", \
"Block device required", \
"Resource busy", \
"File exists", \
"Cross-device link", \
"Operation not supported by device", \
"Not a directory", \
"Is a directory", \
"Invalid argument", \
"Too many open files in system" , \
"Too many open files", \
"Inappropriate ioctl for device", \
"Text file busy", \
"File too large", \
"No space left on device", \
"Illegal seek", \
"Read-only file system", \
"Too many links", \
"Broken pipe", \
"Numerical argument out of domain", \
"Result too large", \
"Resource temporarily unavailable", \
"Operation now in progress", \
"Operation already in progress", \
"Socket operation on non-socket", \
"Destination address required", \
"Message too long", \
"Protocol wrong type for socket", \
"Protocol not available", \
"Protocol not supported", \
"Socket type not supported", \
"Operation not supported", \
"Protocol family not supported", \
"Address family not supported by protocol family", \
"Address already in use", \
"Can't assign requested address", \
"Network is down", \
"Network is unreachable", \
"Network dropped connection on reset", \
"Software caused connection abort", \
"Connection reset by peer", \
"No buffer space available", \
"Socket is already connected", \
"Socket is not connected", \
"Can't send after socket shutdown", \
"Too many references: can't splice", \
"Operation timed out", \
"Connection refused", \
"Too many levels of symbolic links", \
"File name too long", \
"Host is down", \
"No route to host", \
"Directory not empty", \
"Too many processes", \
"Too many users", \
"Disc quota exceeded", \
"Stale NFS file handle", \
"Too many levels of remote in path", \
"RPC struct is bad", \
"RPC version wrong", \
"RPC prog. not avail", \
"Program version wrong", \
"Bad procedure for program", \
"No locks available", \
"Function not implemented", \
"Inappropriate file type or format", \
"Authentication error", \
"Need authenticator", \
"Device power is off", \
"Device error", \
"Value too large to be stored in data type", \
"Bad executable (or shared library)", \
"Bad CPU type in executable", \
"Shared library version mismatch", \
"Malformed Mach-o file", \
"Operation canceled", \
"Identifier removed", \
"No message of desired type", \
"Illegal byte sequence", \
"Attribute not found", \
"Bad message", \
"EMULTIHOP (Reserved)", \
"No message available on STREAM", \
"ENOLINK (Reserved)", \
"No STREAM resources", \
"Not a STREAM", \
"Protocol error", \
"STREAM ioctl timeout", \
"Operation not supported on socket", \
"Policy not found", \
"State not recoverable", \
"Previous owner died", \
"Interface output queue is full"}
#else
#define __S21_LINUX__
#define _ERRORS_MAX_ 133
#define _ERRORS_LIST_  {"Success", \
"Operation not permitted", \
"No such file or directory", \
"No such process", \
"Interrupted system call", \
"Input/output error", \
"No such device or address", \
"Argument list too long", "Exec format error", \
"Bad file descriptor", \
"No child processes", "Resource temporarily unavailable", \
"Cannot allocate memory", \
"Permission denied", \
"Bad address", \
"Block device required", \
"Device or resource busy", \
"File exists", \
"Invalid cross-device link", \
"No such device", \
"Not a directory", \
"Is a directory", \
"Invalid argument", \
"Too many open files in system", \
"Too many open files", \
"Inappropriate ioctl for device", \
"Text file busy", \
"File too large", \
"No space left on device", \
"Illegal seek", \
"Read-only file system", \
"Too many links", \
"Broken pipe", \
"Numerical argument out of domain", \
"Numerical result out of range", \
"Resource deadlock avoided", \
"File name too long", \
"No locks available", \
"Function not implemented", \
"Directory not empty", \
"Too many levels of symbolic links", \
"Unknown error 41", \
"No message of desired type", \
"Identifier removed", \
"Channel number out of range", \
"Level 2 not synchronized", \
"Level 3 halted", \
"Level 3 reset", \
"Link number out of range", \
"Protocol driver not attached", \
"No CSI structure available", \
"Level 2 halted", \
"Invalid exchange", \
"Invalid request descriptor", \
"Exchange full", \
"No anode", \
"Invalid request code", \
"Invalid slot", \
"Unknown error 58", \
"Bad font file format", \
"Device not a stream", \
"No data available", \
"Timer expired", \
"Out of streams resources", \
"Machine is not on the network", \
"Package not installed", \
"Object is remote", \
"Link has been severed", \
"Advertise error", \
"Srmount error", \
"Communication error on send", \
"Protocol error", \
"Multihop attempted", \
"RFS specific error", \
"Bad message", \
"Value too large for defined data type", \
"Name not unique on network", \
"File descriptor in bad state", \
"Remote address changed", \
"Can not access a needed shared library", \
"Accessing a corrupted shared library", \
".lib section in a.out corrupted", \
"Attempting to link in too many shared libraries", \
"Cannot exec a shared library directly",  \
"Invalid or incomplete multibyte or wide character", \
"Interrupted system call should be restarted", \
"Streams pipe error", \
"Too many users", \
"Socket operation on non-socket", \
"Destination address required", \
"Message too long", \
"Protocol wrong type for socket", \
"Protocol not available", \
"Protocol not supported", \
"Socket type not supported", \
"Operation not supported", \
"Protocol family not supported", \
"Address family not supported by protocol", \
"Address already in use", \
"Cannot assign requested address", \
"Network is down", \
"Network is unreachable", \
"Network dropped connection on reset", \
"Software caused connection abort", \
"Connection reset by peer", \
"No buffer space available", \
"Transport endpoint is already connected", \
"Transport endpoint is not connected", \
"Cannot send after transport endpoint shutdown", \
"Too many references: cannot splice", \
"Connection timed out", \
"Connection refused", \
"Host is down", \
"No route to host", \
"Operation already in progress", \
"Operation now in progress", \
"Stale file handle", \
"Structure needs cleaning", \
"Not a XENIX named type file", \
"No XENIX semaphores available", \
"Is a named type file", \
"Remote I/O error", \
"Disk quota exceeded", \
"No medium found", \
"Wrong medium type", \
"Operation canceled", \
"Required key not available", \
"Key has expired", \
"Key has been revoked", \
"Key was rejected by service", \
"Owner died", \
"State not recoverable", \
"Operation not possible due to RF-kill", \
"Memory page has hardware error"}
#endif
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>
#include <math.h>
#include <locale.h>
#include <wchar.h>
#include <limits.h>
#include <stddef.h>
#include <float.h>

#define BUFFSIZE 1024

#define S21_CODE_SPECIFIERS_1 "cdifsu%"
#define S21_CODE_SPECIFIERS_2 "gGeExXonp"
#define S21_CODE_SPECIFIERS S21_CODE_SPECIFIERS_1 /* S21_CODE_SPECIFIERS_2 */

#define S21_CODE_FLAGS_1 "-+ "
#define S21_CODE_FLAGS_2 "#0"
#define S21_CODE_FLAGS S21_CODE_FLAGS_1 /* S21_CODE_FLAGS_2 */

#define S21_CODE_LENGTH_1 "hl"
#define S21_CODE_LENGTH_2 "L"
#define S21_CODE_LENGTH S21_CODE_LENGTH_1 /* S21_CODE_LENGTH_2 */

#define S21_NULL ((void *)0)
#define numspace(val, x, y) (val >= x && val <= y)

typedef long unsigned int s21_size_t;

struct s_format {
  int isInt;
  int flagPlus;
  int flagMinus;
  int flagSpace;
  int width;
  int precision;
  int precisionWillBeSpecified;
  int precisionSetByZero;
  int length_h;
  int length_l;
  int isLongDouble;
  int isAsteriskWidth;
  int isAsteriskFloatWidthDescription;
  int precisionIsNull;
  int widthMustBeWrittenByZero;
  int widthZeroDetected;
  int spec;
};

void *s21_memchr(const void *str, int sym, s21_size_t n);
int s21_memcmp(const void *str1, const void *str2, s21_size_t n);
void *s21_memcpy(void *dest, const void *src, s21_size_t n);
void *s21_memmove(void *dest, const void *src, s21_size_t n);

void* s21_memset(void* b, int c, s21_size_t len);
char* s21_strcat(char*dest , const char* src);
char* s21_strchr(const char* string, int character);
char * s21_strncat(char *dest, const char *src, s21_size_t n);

int s21_strcmp(const char *str1, const char *str2);
int s21_strncmp(const char *str1, const char *str2, size_t n);
char *s21_strcpy(char *dest, const char *src);
char *s21_strncpy(char *dest, const char *src, size_t n);

s21_size_t s21_strlen(const char *string);
char *s21_strerror(int errnum);
void s21_itoa(int num, char *str);
char *s21_strpbrk(const char *str1, const char *str2);
s21_size_t  s21_strcspn(const char *str1, const char *str2);

char *s21_strrchr(const char *str, int c);
size_t s21_strspn(const char *str1, const char *str2);
char *s21_strstr(const char *haystack, const char *needle);
char *s21_strtok(char *str, const char *delim);

int s21_sprintf(char *str, const char *format, ...);
int s21_is_number(int character);
char *s21_strdup(const char *s1);
int extra_is_spec(char c, struct s_format *code_params);
void extra_init_struct(struct s_format *code_params);
void extra_write_char(const char **format, char **str,
                      struct s_format *code_params, char c);
void extra_write_percent(const char **format, char **str);
void extra_b_zero(void *s, s21_size_t n);
void *extra_memalloc(s21_size_t size);
char *extra_itoa(long int n);
char *extra_utoa(unsigned long long int n);
char *extra_ldtoa(long long int n);
char *check_float_max_min_cases(long double f_case, char *str);
long double s21_round(int accuracy, long double number);
char *extra_ftoa(long double f, struct s_format code_params);
char *extra_float_max_conversion(char *str);
long long int extra_find_multiplier(long double fpNumber, int *size);
void extra_convert_decimal(char **str, int *i, float fpNumber, int accuracy);
void extra_convert_integer(double *fpNumber, char **str, int *i,
                           long int multiplier);
void extra_cut_str(char *str, int pres, int isSetByZero);
char *extra_str_new(s21_size_t size);
int extra_count_numerals(long double chislo);
char *extra_dtoa(long double ldNumber, struct s_format code_params);
void extra_convert_dbl_decimal(char **str, int *i, long double chislo,
                              int accuracy);
void extra_convert_dbl_integer(long double *ldblNumber, char **str, int *i, long int multiplier);
int extra_recursion(int *i, char *str);
char *extra_round(char *str, int accuracy, int precisionSetByZero);
void handle_prec(char *buff, struct s_format *code_params);
void handle_flags(char *buff, struct s_format *code_params);
void write_int(char *buff, struct s_format *code_params, char *string);
void handle_string(struct s_format *code_params, char *buff, char *str);
void handle_wide_string(struct s_format *code_params, char *buff, wchar_t *wstr);
void write_float(char *buff, struct s_format *code_params, char *string);
int parser(const char **inputLine, struct s_format *inputLineParams);
void extra_write_in_buff(const char **format, char **str,
                          struct s_format *code_params, va_list vlist,
                          char *buff);
void exp_num(char *mass, const char* format, ...);
int exp_num_error(const char *mass, const char **c);
char *str_to_mass(const char **str, char* mass, int *n, const char* format, size_t i, int *error, int width);
long double s21_atof(const char *str);
int oct_pars(char** mass, const char** str, int *n, const char *format, size_t i, int *error, int width);
long oct_to_dec(char* mass);
int hex_pars(char** mass, const char** str, int *n, const char *format, size_t i, int *error, int width);
long hex_to_dec(char* mass);
long long int s21_atoi(const char *str);

void *s21_to_upper(const char *str);
void *s21_to_lower(const char *str);
void s21_reverse_string(char *line_for_num, int size);
void *s21_insert(const char *src, const char *str, s21_size_t start_index);
void *s21_trim(const char *src, const char *trim_chars);

#endif  // SRC_S21_STRING_H_
