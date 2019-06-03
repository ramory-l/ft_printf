#include "ft_printf.h"

void	ft_choose_print(va_list ap, cc *format, t_printf *data, t_buffer *bf)
{
	if (data->type == 'd' || data->type == 'i' ||
		data->type == 'o' || data->type == 'u' ||
		data->type == 'x' || data->type == 'X')
		ft_dioux_x(ap, format, data, bf);
	if (data->type == 'c')
		ft_print_char(ap, data, bf);
	if (data->type == 's')
		ft_print_string(ap, data, bf);
	if (data->type == '%')
		ft_print_percent(data, bf);
}
