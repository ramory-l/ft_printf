#include "ft_printf.h"

static void		ft_print_percentage(const char *format, t_printf *data)
{
	data->nbr = NULL;
	data->nbr = ft_strjoin(data->nbr, "%");
	if (!(data->flags & FLAG_MINUS) && data->width)
		data->nbr = ft_fill_spaces(data->nbr, '<', data->width - 1);
	if (data->flags & FLAG_MINUS && data->width)
		data->nbr = ft_fill_spaces(data->nbr, '>', data->width - 1);
	ft_putstr(data->nbr);
	data->printed += ft_strlen(data->nbr);
}

static void		ft_print_ptr(va_list ap, const char *format, t_printf *data)
{
	data->nbr =
		ft_itoa_base_unsigned((unsigned long long int)va_arg(ap, void*), 16);
	data->nbr = ft_strjoin("0x", data->nbr);
	ft_putstr(data->nbr);
	data->printed += ft_strlen(data->nbr);
}

void			ft_choose_print(va_list ap, const char *format, t_printf *data)
{
	if (data->type == 'd' || data->type == 'i' ||
		data->type == 'o' || data->type == 'u' ||
		data->type == 'x' || data->type == 'X')
		ft_print_dioux_x(ap, format, data);
	if (data->type == 'c')
		ft_print_char(ap, format, data);
	if (data->type == 's')
		ft_print_string(ap, format, data);
	if (data->type == 'p')
		ft_print_ptr(ap, format, data);
	if (data->type == '%')
		ft_print_percentage(format, data);
}
