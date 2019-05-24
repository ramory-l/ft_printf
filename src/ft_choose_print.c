#include "ft_printf.h"

static void		ft_print_percent(const char *format, t_printf *data)
{
	int turn;
	char buffer[512];

	turn = 0;
	ft_bzero(buffer, sizeof(buffer));
	buffer[0] = '%';
	data->len = 1;
	if (!(data->flags & FLAG_MINUS) && data->width)
		turn = ft_fill_spaces(buffer, '<', data->width, data->len);
	if (data->flags & FLAG_MINUS && data->width)
		turn = ft_fill_spaces(buffer, '>', data->width, data->len);
	if (turn)
		data->len = data->width;
	write(1, buffer, data->len);
	data->printed += data->len;
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
