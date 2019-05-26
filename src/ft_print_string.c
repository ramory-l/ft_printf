#include "ft_printf.h"

static void	ft_width_accuracy(char *buffer, t_printf *data)
{
	int turn;

	turn = 0;
	if (data->accuracy > 0 && data->accuracy < data->len)
	{
		ft_clean_buff(buffer, data->accuracy, data->len);
		data->len = data->accuracy;
	}
	if (data->width > data->len && !(data->flags & FLAG_MINUS))
		turn = ft_fill_spaces(buffer, '<', data->width, data->len);
	if (data->width > data->len && data->flags & FLAG_MINUS)
		turn = ft_fill_spaces(buffer, '>', data->width, data->len);
	if (turn)
		data->len = data->width;
}

void		ft_print_string(va_list ap, const char *format, t_printf *data)
{
	char buffer[512];

	data->nbr = va_arg(ap, char *);
	data->len = 0;
	if (!data->nbr)
	{
		ft_putstr("(null)");
		data->printed += 6;
		return ;
	}
	ft_bzero(buffer, sizeof(buffer));
	ft_fill_buff(0, buffer, data->nbr);
	while (buffer[data->len])
		data->len++;
	ft_width_accuracy(buffer, data);
	write(1, buffer, data->len);
	data->printed += data->len;
}