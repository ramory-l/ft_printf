#include "ft_printf.h"

static int ft_find_length(ulli value, int base)
{
	int len;

	len = 0;
	while (value)
	{
		value /= base;
		len++;
	}
	return (len);
}

char *ft_itoa_base_unsigned(ulli value, int base, t_printf *data)
{
	int len;
	char *radix;
	char *number;

	if (base == 17)
	{
		radix = "0123456789ABCDEF";
		base--;
	}
	else
		radix = "0123456789abcdef";
	if (value == 0)
		return ("0");
	len = ft_find_length(value, base);
	data->len = len;
	number = ft_strnew(len);
	while (len--)
	{
		number[len] = radix[value % base];
		value /= base;
	}
	return (number);
}
