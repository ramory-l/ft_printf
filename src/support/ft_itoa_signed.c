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

void		ft_itoa_signed(lli value, t_printf *data, t_buffer *bf)
{
	int len;
	int	sign;

	sign = 0;
	if (value == 0)
	{
		bf->temp[0] = '0';
		data->len = 1;
		return ;
	}
	value = ft_check_sign(value, &sign);
	len = ft_find_length(value);
	len += sign;
	data->len = len;
	if (sign)
		bf->temp[0] = '-';
	while (len-- > sign)
	{
		bf->temp[len] = value % 10 + '0';
		value /= 10;
	}
}
