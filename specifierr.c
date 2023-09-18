#include "main.h"

/**
 * get_specifier - get specifier
 *
 * @s: string
 *
 * Return: int
*/

int (*get_specifier(char *s))(va_list ap, parameters *params)
{
	specifier_t specifiers[] = {
		{"c", print_char},
		{"d", print_int},
		{"i", print_int},
		{"s", print_string},
		{"%", print_percent},
		{"b", print_binary},
		{"o", print_octal},
		{"u", print_unsigned},
		{"x", print_hex},
		{"X", print_HEX},
		{"p", print_address},
		{"S", print_S},
		{"r", print_rev},
		{"R", print_rot13},
		{NULL, NULL}
	};
	int x = 0;

	while (specifier[x].specifier)
	{
		if (*s == specifiers[x].specifier[0])
		{
			return (specifiers[x].f);
		}
		x++;
	}
	return (NULL);
}

/**
 * get_print_func - print funt
 *
 * @s: stirng
 * @ap: argument
 * @params: parametes
 *
 * Return: int
*/

int get_print_func(char *s, va_list ap, parameters *params)
{
	int (*f)(va_list, parameters *) = get_specifier(s);

	if (f)
		return (f(ap, params));
	return (0);
}

/**
 * get_flag - get flag
 *
 * @s: string
 * @params: parameters
 *
 * Return: int
*/

int get_flag(char *s, parameters *params)
{
	int i = 0;

	switch (*s)
	{
		case '+':
			i = params->plus = 1;
			break;
		case ' ':
			i = params->space = 1;
			break;
		case '#':
			i = params->hashtag = 1;
			break;
		case '-':
			i = params->minus = 1;
			break;
		case '0':
			i = params->zero = 1;
			break;
	}
	return (i);
}

/**
 * get_modifier -get modifier
 *
 * @s: string
 * @params: parameters
 *
 * Return: int
*/

int get_modifier(char *s, parameters *params)
{
	int x = 0;

	switch (*s)
	{
		case 'h':
			i = params->h = 1;
			break;
		case 'l':
			i = params->l = 1;
			break;
	}
	return (x);
}

/**
 * get_width - get width
 *
 * @s: string
 * @params: parameter
 * @ap: argument
 *
 * Return: char
*/

char *get_width(char *s, parameters *params, va_list ap)
{
	int x = 0;

	if (*s == '*')
	{
		x = va_arg(ap, int);
		s++;
	}
	else
	{
		while (_isdigit(*s))
			x = x * 10 + (*s++ - '0');
	}
	params->width = x;
	return (s);
}
