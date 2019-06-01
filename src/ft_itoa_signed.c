#include "ft_printf.h"

static lli	ft_check_sign(lli value, int *sign)
{
	if (value < 0)
	{
		value *= -1;
		*sign = 1;
	}
	return (value);
}

static int	ft_find_length(lli value)
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

void		ft_itoa_signed(lli value, t_buffer *bf)
{
	int len;
	int temp;
	int	sign;

	sign = 0;
	if (value == 0)
	{
		bf->buffer[bf->s] = '0';
		bf->s++;
		return ;
	}
	value = ft_check_sign(value, &sign);
	len = ft_find_length(value);
	len += sign;
	temp = len;
	if (sign)
		bf->buffer[bf->s] = '-';
	bf->s += len - 1;
	while (len-- > sign)
	{
		bf->buffer[bf->s] = value % 10 + '0';
		bf->s--;
		value /= 10;
	}
	bf->s += temp - sign + 1;
}
