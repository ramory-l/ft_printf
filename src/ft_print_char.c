#include "ft_printf.h"

static void	ft_width_accuracy(char *buffer, t_printf *data)
{
	int turn;

	turn = 0;
	if (buffer[0])
	{
		if (data->width > data->len && !(data->flags & FLAG_MINUS))
			turn = ft_fill_spaces(buffer, '<', data->width, data->len);
		if (data->width > data->len && data->flags & FLAG_MINUS)
			turn = ft_fill_spaces(buffer, '>', data->width, data->len);
		if (turn)
			data->len = data->width;
	}
	else
	{
		while (data->len < data->width)
		{
			buffer[turn] = ' ';
			data->len++;
		}
	}
}

void	ft_print_char(va_list ap, const char *format, t_printf *data)
{
	char buffer[512];

	buffer[0] = va_arg(ap, int);
	data->len = 1;
	ft_width_accuracy(buffer, data);
	write(1, buffer, data->len);
	data->printed += data->len;
}