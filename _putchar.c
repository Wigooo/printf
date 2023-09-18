#include "main.h"

/**
 * _puts - prints string followed by newline
 * @str: string to print
 * Return: void
 */

int _puts(char *str)
{
	char *a = str;

	while (*str)
		_putchar(*str++);
	return (str - a);
}


/**
 * _putchar - write character c to stdout
 * @c: character to be printed
 * Return: 1 if success
 *		-1 when Error, and err. no is set appropriately.
 */

int _putchar(int c)
{
	static char buf[BUF_SIZE];
	static int i;

	if (c == BUF_FLUSH || i >= BUF_SIZE)
	{
		write(1, buf, i);
		i = 0;
	}

	if (c != BUF_FLUSH)
	{
		buf[i++] = c;
	}

	return (1);
}
