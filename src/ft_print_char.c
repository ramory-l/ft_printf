#include "ft_printf.h"

static void	ft_width(t_printf *data)
{
	if (data->width > 1)
		data->nbr = ft_fill_spaces(data->nbr, '<', data->width - 1);
}

void	ft_print_char(va_list ap, const char *format, t_printf *data)
{
	data->nbr = ft_strnew(1);
	data->nbr[0] = va_arg(ap, int);
	ft_width(data);
	ft_putstr(data->nbr);
	data->printed += 1;
}