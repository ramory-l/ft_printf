#include "ft_printf.h"

int	type(char c)
{
	if (c == 'd' || c == 'i' || c == 'o' ||
		c == 'u' || c == 'x' || c == 'X' ||
		c == 'c' || c == 's' || c == 'p' ||
		c == '%')
		return (1);
	return (0);
}
