#include "main.h"

/**
 * init_params - let struct field cleared and buf reset.
 * @params: parameters struct
 * @ap: pointer of arguments
 * Return: void
 */

void init_params(parameters *params, va_list ap)
{
	params->unsign = 0;

	params->plus = 0;
	params->space = 0;
	params->hashtag = 0;
	params->zero = 0;
	params->minus = 0;

	params->width = 0;
	params->percision = UNIT_MAX;

	params->h = 0;
	params->l = 0;
	(void)ap;
}
