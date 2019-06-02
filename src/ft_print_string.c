#include "ft_printf.h"

static int ft_width_accuracy(char *str, t_printf *data, t_buffer *bf)
{
	int i;

	i = 0;
	if (data->width > 0)
	{
		if (data->acc)
		{
		}
	}
	else if (data->acc)
	{
		while (str[i] && i != data->accuracy)
		{
			bf->buffer[bf->s] = str[i];
			bf->s++;
			i++;
			ft_check_buffer(data, bf);
		}
		return (1);
	}
	return (0);
}

void ft_print_string(va_list ap, t_printf *data, t_buffer *bf)
{
	char *str;

	str = va_arg(ap, char *);
	if (ft_width_accuracy(str, data, bf))
		return ;
	while (*str)
	{
		bf->buffer[bf->s] = *str;
		bf->s++;
		str++;
		ft_check_buffer(data, bf);
	}
}