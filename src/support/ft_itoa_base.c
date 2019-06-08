#include "ft_printf.h"

static int	ft_find_length(ulli value, int base)
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

void		ft_itoa_base(ulli value, int base, t_printf *data, t_buffer *bf)
{
	int		len;
	char	*radix;

	if (base == 17)
	{
		radix = "0123456789ABCDEF";
		base--;
	}
	else
		radix = "0123456789abcdef";
	if (value == 0)
	{
		bf->temp[0] = '0';
		data->len = 1;
		return ;
	}
	len = ft_find_length(value, base);
	data->len = len;
	while (len--)
	{
		bf->temp[len] = radix[value % base];
		value /= base;
	}
}
