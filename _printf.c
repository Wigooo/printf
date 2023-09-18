#include "main.h"

/**
 * _printf - the project
 *
 * @format: format
 *
 * Return: int
*/

int _printf(const char *format, ...)
{
	int x = 0;
	va_list ap;
	char *p, *start;
	parameters params = PARAMS_INIT;

	va_start(ap, format);

	if (!format || (format[0] == '%' && !format[1]))
		return (-1);
	if (format[0] == '%' && format[1] == ' ' && !format[2])
		return (-1);
	for (p = (char *)format; *p; p++)
	{
		init_params(&params, ap);
		if (*p != '%')
		{
			x += _putchar(*p);
			continue;
		}
		start = p;
		p++;
		while (get_flag(p, &params))
		{
			p++;
		}

		p = get_width(p, &params, ap);
		p = get_precision(p, &params, ap);
		if (get_modifier(p, &params))
			p++;
		if (!get_specifier(p))
			x += print_from_to(start, p,
					params.l || params.h ? p - 1 : 0);
		else
			x += get_print_func(p, ap, &params);
	}
	_putchar(BUF_FLUSH);
	va_end(ap);
	return (x);
}
