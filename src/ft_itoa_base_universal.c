#include "ft_printf.h"

char	*ft_itoa_base_universal(unsigned long long int value, int base)
{
	int						len;
	unsigned long long int	temp;
	char					*radix;
	char					*number;

	len = 0;
	temp = value;
	radix = "0123456789ABCDEF";
	if (value == 0)
		return ("0");
	while (temp)
	{
		temp /= base;
		len++;
	}
	number = (char *)malloc(sizeof(char) * (len + 1));
	while (len--)
	{
		number[len] = radix[value % base];
		value /= base;
	}
	return (number);
}
