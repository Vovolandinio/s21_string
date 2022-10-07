### env
UNAME:=$(shell uname -s)

ifeq ($(UNAME), Linux)
D_ENV=__LINUX__
endif
ifeq ($(UNAME), Darwin)
D_ENV=__MAC_OS__
endif

### C
CC=gcc
STAT_LIBC_BUILD=ar rcs

### src s21_string.a
STAT_LIBC_NAME=s21_string.a
CFLAGS=-Wall -Werror -Wextra -std=c11 -D$(D_ENV)
CLIBS_TEST=
HEADERS=s21_string.h
SOURCES=\
s21_strlen.c \
s21_strncat.c \
s21_strcpy.c \
s21_memchr.c \
s21_memcmp.c \
s21_memcpy.c \
s21_memmove.c \
s21_memset.c \
s21_strcat.c \
s21_strchr.c \
s21_strcmp.c \
s21_strncmp.c \
s21_strncpy.c \
s21_strcspn.c \
s21_strerror.c \
s21_strpbrk.c \
s21_strrchr.c \
s21_strspn.c \
s21_strstr.c \
s21_strtok.c \
s21_to_upper.c \
s21_to_lower.c \
s21_insert.c \
s21_trim.c \
s21_sprintf.c \
s21_supfunc.c

OBJECTS=$(SOURCES:.c=.o)

## tests
TESTS_NAME=tests.exe
TESTS_CHECK=s21_string_tests.check
SOURCES_TEST=tests.c
OBJECTS_TEST=$(SOURCES_TEST :%.c=%.o)
CFLAGS_TEST=$(CFLAGS) $(shell pkg-config --cflags check) -g
CLIBS_TEST=-lcheck $(shell pkg-config --libs check)

### gcov
GCOV_NAME=gcov_report_tests.exe
INFO_GCOV=gcov_report_tests.info
GCOV_DIR=tests_coverage
CFLAGS_GCOV=$(CFLAGS_TEST) -fprofile-arcs -ftest-coverage
CLIBS_GCOV=$(CLIBS_TEST)

### memory leaking
ifeq ($(UNAME), Linux)
LEAKS_CHECKING=valgrind -q --track-origins=yes --tool=memcheck --leak-check=full ./$(TESTS_NAME) ./$(STAT_LIBC_NAME) ./$(GCOV_NAME)
endif
ifeq ($(UNAME), Darwin)
LEAKS_CHECKING=CK_FORK=no leaks --atExit -- ./$(TESTS_NAME) ./$(STAT_LIBC_NAME) ./$(GCOV_NAME)
endif

### open
ifeq ($(UNAME), Linux)
OPEN=xdg-open
endif
ifeq ($(UNAME), Darwin)
OPEN=open
endif

### make

.PHONY: all clean gcov_report test html_rebuild check_rebuild

all: clean s21_string.a test gcov_report checking

html_rebuild: clean gcov_report
test_rebuild: clean test

checking:
	-cppcheck $(SOURCES) $(HEADERS)
	-python3 ../materials/linters/cpplint.py --extensions=c $(SOURCES)
	-python3 ../materials/linters/cpplint.py --extensions=h $(HEADERS)
	-$(LEAKS_CHECKING)

### build
$(SOURCES_TEST): $(TESTS_CHECK)
	checkmk $(TESTS_CHECK) > $(SOURCES_TEST)

%.o: %.c
	$(CC) -c $(CFLAGS) -lm $< -o $@

### build s21_string.a
$(STAT_LIBC_NAME): $(OBJECTS)
	$(STAT_LIBC_BUILD) $(STAT_LIBC_NAME) $(OBJECTS)

### test
test: $(SOURCES_TEST)
	$(CC) $(CFLAGS_TEST) $(SOURCES) $(SOURCES_TEST) -o $(TESTS_NAME) $(CLIBS_TEST)
	-./$(TESTS_NAME)

### coverage
gcov_report: $(SOURCES) $(SOURCES_TEST)
	$(CC) $(SOURCES) $(SOURCES_TEST) -o $(GCOV_NAME) $(CFLAGS_TEST) $(CLIBS_TEST) --coverage
	-./$(GCOV_NAME) -lcov
	-mkdir $(GCOV_DIR)
	lcov -c -d . -o $(GCOV_DIR)/$(INFO_GCOV)
	genhtml -o $(GCOV_DIR)/results/ $(GCOV_DIR)/$(INFO_GCOV)

### clean
 clean_gcov_report:
	-@lcov -z -d .
	-@rm -f $(GCOV_NAME)

clean_test:
	-@rm -f $(SOURCES_TEST)

clean_s21_string_a:
	-@rm -f $(STAT_LIBC_NAME)

clean: clean_gcov_report clean_test clean_s21_string_a
	-@rm -rf $(GCOV_DIR)
	-@rm -f *.o
	-@rm -f *.gcda
	-@rm -f *.gcno
	-@rm -f *.exe

### open
open_html:
	$(OPEN) $(GCOV_DIR)/results/index.html
