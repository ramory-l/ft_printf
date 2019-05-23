#include "ft_printf.h"

static int ft_find_length(lli value)
{
	int len;

	len = 0;
	while (value)
	{
		value /= 10;
		len++;
	}
	return (len);
}

char *ft_itoa_signed(lli value, t_printf *data)
{
	int len;
	int	sign;
	char *number;

	sign = 0;
	if (value == 0)
		return ("0");
	if (value < 0)
	{
		value *= -1;
		sign = 1;
	}
	len = ft_find_length(value);
	len += sign;
	data->len = len;
	number = ft_strnew(len);
	if (sign)
		number[0] = '-';
	while (len-- > sign)
	{
		number[len] = value % 10 + '0';
		value /= 10;
	}
	return (number);
}
