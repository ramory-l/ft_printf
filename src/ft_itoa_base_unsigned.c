#include "ft_printf.h"

static int ft_find_length(unsigned long long int value, int base)
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

char *ft_itoa_base_unsigned(unsigned long long int value, int base)
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
	number = (char *)malloc(sizeof(char) * (len + 1));
	while (len--)
	{
		number[len] = radix[value % base];
		value /= base;
	}
	return (number);
}
