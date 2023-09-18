#include "main.h"

/**
 * convert - convert
 *
 * @num: number
 * @base: base
 * @flags: flags
 * @params: paramterts
 *
 * Return: char
*/

char *convert(long int num, int base, int flags, parameters *params)
{
	static char *array;
	static char buffer[50];
	char sign = 0;
	char *ptr;
	unsigned long n = num;
	(void)params;

	if (!(flags & CONVERT_UNSIGNED) && num < 0)
	{
		n = -num;
		sign = '-';
	}
	array = flags & CONVERT_LOWERCASE ? "0123456789abcdef" : "0123456789ABCDEF";
	ptr = &buffer[49];
	*ptr = '\0';

	do {
		*--ptr = array[n % base];
		n /= base;
	} while (n != 0);

	if (sign)
		*--ptr = sign;
	return (ptr);
}

/**
 * print_unsigned - print unsigned
 *
 * @ap: argument
 * @params: parmaeters
 *
 * Return: int
*/

int print_unsigned(va_list ap, parameters *params)
{
	unsigned int x;

	if (params->l)
		x = (unsigned long)va_arg(ap, unsigned long);
	else if (params->h)
		x = (unsigned short int)va_arg(ap, unsigned int);
	else
		x = (unsigned int)va_arg(ap, unsigned int);
	params->unsign = 1;
	return (print_number(convert(l, 10, CONVERT_UNSIGNED, params), params));
}

/**
 * print_address - print address
 *
 * @ap: argument
 * @params: parameters
 *
 * Return: int
*/

int print_address(va_list ap, parameters *params)
{
	unsigned long int n = va_arg(ap, unsigned long int);
	char *str;

	if (!n)
		return (_puts("(nil)"));

	str = convert(n, 16, CONVERT_UNSIGNED | CONVERT_LOWERCASE, params);
	*--str = 'x';
	*--str = '0';
	return (print_number(str, params));
}
