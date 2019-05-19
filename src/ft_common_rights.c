#include "ft_printf.h"

void	ft_minus_width_rule(t_printf *data)
{
	data->len = ft_strlen(data->nbr);
	if (!(data->flags & FLAG_MINUS) && data->width > data->len)
		data->nbr = ft_fill_spaces(data->nbr, '<', data->width - data->len);
	if (data->flags & FLAG_MINUS && data->width > data->len)
		data->nbr = ft_fill_spaces(data->nbr, '>', data->width - data->len);
}