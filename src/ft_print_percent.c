#include "ft_printf.h"

static int	ft_width(t_printf *data, t_buffer *bf)
{
	if (data->width > data->len && !(data->flags & FLAG_MINUS))
		ft_fill_bf_spaces(data, bf);
	else if (data->width > data->len && data->flags & FLAG_MINUS)
	{
		ft_fill_bf(data, bf);
		ft_fill_bf_spaces(data, bf);
		return (1);
	}
	return (0);
}

void ft_print_percent(t_printf *data, t_buffer *bf)
{
	bf->temp[0] = '%';
	data->len = 1;
	if (ft_width(data, bf))
		return ;
	ft_fill_bf(data, bf);
}