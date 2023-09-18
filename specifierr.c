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
