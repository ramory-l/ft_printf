#include "ft_printf.h"

char	*ft_itoa_base_unsigned(unsigned long long int number, int base)
{
	long int				len;
	char					*num;
	unsigned long long int	temp;
	char					*radix;

	len = 0;
	temp = number;
	if (number == 0)
		return ("0");
	if (base == 17 && base--)
		radix = "0123456789ABCDEF";
	else
		radix = "0123456789abcdef";
	while (++len && (number /= base))
		;
	num = (char *)malloc(sizeof(char) * (len + 1));
	while (len--)
	{
		num[len] = radix[temp % base];
		temp /= base;
	}
	return (num);
}
