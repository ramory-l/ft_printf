#include "ft_printf.h"

static void	ft_plus_width(t_printf *data, t_buffer *bf)
{
	if ((data->flags & FLAG_SPACE || data->width > data->len) &&
		!(data->flags & FLAG_ZERO))
	{
		if (data->width > data->len)
			ft_fill_bf_spaces(data, bf);
		else
		{
			if (bf->temp[0] != '-')
			{
				bf->buffer[bf->s] = ' ';
				bf->s++;
				ft_check_buffer(data, bf);
			}
		}
	}
	if (data->width > data->len && data->flags & FLAG_ZERO)
	{
		if (data->flags & FLAG_PLUS)
			data->len++;
		ft_fill_bf_zeroes(data, bf);
	}
}

void		ft_print_di(t_printf *data, t_buffer *bf)
{
	if (data->flags & FLAG_PLUS && !data->sign && bf->temp[0] != '-')
	{
		bf->buffer[bf->s] = '+';
		bf->s++;
		ft_check_buffer(data, bf);
	}
	ft_plus_width(data, bf);
	ft_fill_bf(data, bf);
}
