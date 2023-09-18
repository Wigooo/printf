#ifndef _PROJECT_H
#define _PROJECT_H

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>
#include <limits.h>

#define BUF_SIZE 1024
#define BUF_FLUSH -1

#define NULL_STRING "(null)"

#define PARAMS_INIT {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}

#define CONVERT_LOWERCASE	1
#define CONVERT_UNSIGNED	2

/**
 * struct parameters - parameters struct
 *
 * @unsign: 1 if there is unsigned value
 * @plus: 1 if there is a plus flag
 * @minus: 1 if there is a minus flag
 * @zero: if there is a zero flag
 * @space: 1 if there is a space flag
 * @hashtag: 1 if there is a hashtag flag
 * @width: width
 * @precision: precision
 * @h: 1 if there is a h modifier
 * @l: 1 if there is a l modifier
*/

typedef struct parameters
{
	unsigned int unsign	: 1;
	unsigned int plus	: 1;
	unsigned int minus	: 1;
	unsigned int zero	: 1;
	unsigned int space	: 1;
	unsigned int hashtag	: 1;
	unsigned int width;
	unsigned int precision;
	unsigned int h		: 1;
	unsigned int l		: 1;
} parameters;

/**
 * struct specifier - specifier struct
 *
 * @specifier: specifier
 * @f: function
*/

typedef struct specifier
{
	char *specifier;
	int (*f)(va_list, parameters *);
} specifier_t;

int _puts(char *str);
int _putchar(int c);
int _printf(const char *format, ...);
int print_char(va_list ap, parameters *params);
int print_int(va_list ap, parameters *params);
int print_string(va_list ap, parameters *params);
int print_string(va_list ap, parameters *params);
int print_S(va_list ap, parameters *params);
char *convert(long int num, int base, int flags, parameters *params);
int print_unsigned(va_list ap, parameters *params);
int print_address(va_list ap, parameters *params);
int (*get_specifier(char *s))(va_list ap, parameters *params);
int get_print_func(char *s, va_list ap, parameters *params);
int get_flag(char *s, parameters *params);
int get_modifier(char *s, parameters *params);
int *get_width(char *s, parameters *params, va_list ap);
int print_hex(va_list ap, parameters *params);
int print_HEX(va_list ap, parameters *params);
int print_binary(va_list ap, parameters *params);
int print_octal(va_list ap, parameters *params);
int print_from_to(char *start, char *stop, char *except);
int print_rev(va_list ap, parameters *params);
int print_rot13(va_list ap, parameters *params);
int _isdigit(int c);
int _strlen(char *s);
int print_number(char *str, parameters *params);
int print_number_right_shift(char *str, parameters *params);
int print_number_left_shift(char *str, parameters *params);
void init_params(parameters *params, va_list ap);
char *get_precision(char *p, parameters *params, va_list ap);

#endif
