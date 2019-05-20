#include "ft_printf.h"

static void	ft_string_width_acc(t_printf *data)
{
	data->len = ft_strlen(data->nbr);
	if (data->accuracy > 0 && data->accuracy < data->len)
	{
		data->temp = ft_strdup(data->nbr);
		data->nbr = ft_strsub(data->temp, 0, data->accuracy);
		free(data->temp);
	}
	data->len = ft_strlen(data->nbr);
	if (!(data->flags & FLAG_MINUS) && data->width > data->len)
		data->nbr = ft_fill_spaces(data->nbr, '<', data->width - data->len);
	if (data->flags & FLAG_MINUS && data->width > data->len)
		data->nbr = ft_fill_spaces(data->nbr, '>', data->width - data->len);
}

void		ft_print_string(va_list ap, const char *format, t_printf *data)
{
	data->nbr = va_arg(ap, char *);
	if (!data->nbr)
	{
		ft_putstr("(null)");
		data->printed += 6;
		return ;
	}
	ft_string_width_acc(data);
	ft_putstr(data->nbr);
	data->printed += ft_strlen(data->nbr);
}