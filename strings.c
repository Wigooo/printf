#include "main.h"

/**
 * get_precision - get precision
 *
 * @p: format
 * @params: parameter
 * @ap: argumemnt
 *
 * Return: char
*/

char *get_precision(char *p, parameters *params, va_list ap)
{
	int x = 0;

	if (*p != '.')
		return (p);
	p++;
	if (*p == '*')
	{
		x = va_arg(ap, int);
		p++;
	}
	else
	{
		while (_isdigit(*p))
			x = x * 10 + (*p++ - '0');
	}
	params->precision = x;
	return (p);
}
