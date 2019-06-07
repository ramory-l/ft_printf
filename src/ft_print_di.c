#include "ft_printf.h"

static void	ft_accuracy(t_printf *data, t_buffer *bf)
{
	int i;

	i = data->len;
	while (i < data->accuracy)
	{
		bf->buffer[bf->s] = '0';
		bf->s++;
		i++;
		ft_check_buffer(data, bf);
	}
}

static void	ft_width(t_printf *data, t_buffer *bf)
{
	int i;

	if (data->width > data->accuracy && data->width > data->len &&
		data->accuracy < data->len)
	{
		
	}
}

void ft_print_di(t_printf *data, t_buffer *bf)
{
	if (data->flags & FLAG_MINUS)
	{
		if (!data->sign && data->flags & FLAG_PLUS)
		{
			bf->buffer[bf->s] = '+';
			bf->s++;
			ft_check_buffer(data, bf);
		}
		else if (data->sign)
		{
			bf->buffer[bf->s] = '-';
			bf->s++;
			ft_check_buffer(data, bf);
		}
		if (data->width > data->accuracy && data->width > data->len)
			ft_width(data, bf);
	}
	else
	{

	}
	ft_fill_bf(data, bf);
}
