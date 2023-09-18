#include "main.h"

/**
 * print_hex - print hex
 *
 * @ap: argument
 * @params: parameters
 *
 * Return: int
*/

int print_hex(va_list ap, parameters *params)
{
	unsigned long x;
	int c = 0;
	char *str;

	if (params->l)
		x = (unsigned long)va_arg(ap, unsigned long);
	else if (params->h)
		x = (unsigned short int)va_arg(ap, unsigned int);
	else
		x = (unsigned int)va_arg(ap, unsigned int);

	str = convert(x, 16, CONVERT_UNSIGNED | CONVERT_LOWERCASE, params);
	if (params->hashtag && x)
	{
		*--str = 'x';
		*--str = '0';
	}
	params->unsign = 1;
	return (c += print_number(str, params));
}

/**
 * print_HEX - print hex
 *
 * @ap: argument
 * @params: parameters
 *
 * Return: int
*/

int print_HEX(va_list ap, parameters *params)
{
	unsigned long x;
	int c = 0;
	char *str;


	if (params->l)
		x = (unsigned long)va_arg(ap, unsigned long);
	else if (params->h)
		x = (unsigned short int)va_arg(ap, unsigned int);
	else
		x = (unsigned int)va_arg(ap, unsigned int);

	str = convert(x, 16, CONVERT_UNSIGNED, params);
	if (params->hashtag && x)
	{
		*--str = 'x';
		*--str = '0';
	}
	params->unsign = 1;
	return (c += print_number(str, params));
}

/**
 * print_binary - print binary
 *
 * @ap: argument
 * @params: parameters
 *
 * Return: int
*/

int print_binary(va_list ap, parameters *params)
{
	unsigned int n = va_arg(ap, unsigned int);
	char *str = convert(n, 2, CONVERT_UNSIGNED, params);
	int c = 0;

	if (params->hashtag && n)
		*--str = '0';
	params->unsign = 1;
	return (c += print_number(str, params));
}

/**
 * print_octal - print octal
 *
 * @ap: arghument
 * @params: parameters
 *
 * Return: int
*/

int print_octal(va_list ap, parameters *params)
{
	unsigned long x;
	char *str;
	int c = 0;

	if (params->l)
		x = (unsigned long)va_arg(ap, unsigned long);
	else if (params->h)
		x = (unsigned short int)va_arg(ap, unsigned int);
	else
		x = (unsigned int)va_arg(ap, unsigned int);

	str = convert(x, 8, CONVERT_UNSIGNED, params);

	if (params->hashtag && x)
	{
		*--str = '0';
	}
	params->unsign = 1;
	return (c += print_number(str, params));
}
