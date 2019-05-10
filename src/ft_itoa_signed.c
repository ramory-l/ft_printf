#include "ft_printf.h"

static int ft_find_length(long long int value)
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

char *ft_itoa_signed(long long int value)
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
	number = (char *)malloc(sizeof(char) * (len + 1));
	if (sign)
		number[0] = '-';
	while (len-- > sign)
	{
		number[len] = value % 10 + '0';
		value /= 10;
	}
	return (number);
}
