#include "ft_printf.h"

static void		ft_print_percent(const char *format, t_printf *data)
{
	int	i;
	char buffer[512];

	i = 0;
	ft_bzero(buffer, sizeof(buffer));
	if (!(data->flags & FLAG_MINUS) && data->width)
		ft_fill_spaces(buffer, '<', "%", data->width);
	else if (data->flags & FLAG_MINUS && data->width)
		ft_fill_spaces(buffer, '>', "%", data->width);
	else
		buffer[0] = '%';
	ft_putstr(buffer);
	data->printed += ft_strlen(buffer);
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
		ft_print_percent(format, data);
}
