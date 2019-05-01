#include "ft_printf.h"

char	*ft_itoa_signed(long long int number)
{
	int				len;
	int				sign;
	char			*num;
	int				temp;

	len = 0;
	sign = 0;
	if (number == 0)
		return ("0");
	if (number < 0)
	{
		number *= -1;
		sign = 1;
	}
	temp = number;
	while (++len && (number /= 10))
		;
	len += sign;
	num = (char *)malloc(sizeof(char) * (len + 1));
	if (sign)
		num[0] = '-';
	while (len-- > sign)
	{
		num[len] = temp % 10 + '0';
		temp /= 10;
	}
	return (num);
}
