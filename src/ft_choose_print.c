#include "ft_printf.h"

static void		ft_print_percent(const char *format, t_printf *data)
{
	char buffer[512];

	ft_bzero(buffer, sizeof(buffer));
	buffer[0] = '%';
	if (!(data->flags & FLAG_MINUS) && data->width)
		ft_fill_spaces(buffer, '<', "%", data->width);
	if (data->flags & FLAG_MINUS && data->width)
		ft_fill_spaces(buffer, '>', "%", data->width);
	ft_putstr(buffer);
	data->printed += ft_strlen(buffer);
}

static void		ft_print_ptr(va_list ap, const char *format, t_printf *data)
{
	data->nbr =
		ft_itoa_base_unsigned((ulli)va_arg(ap, void*), 16, data);
	data->nbr = ft_strjoin("0x", data->nbr);
	data->len += 2;
	write(1, data->nbr, data->len);
	data->printed += data->len;;
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
