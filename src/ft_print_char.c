#include "ft_printf.h"

void	ft_print_char(va_list ap, t_printf *data, t_buffer *bf)
{
	data->len = 1;
	if (data->width > data->len && !(data->flags & FLAG_MINUS))
		ft_fill_spaces_oux(data, bf);
	bf->buffer[bf->s] = va_arg(ap, int);
	bf->s++;
	if (data->width > data->len && data->flags & FLAG_MINUS)
		ft_fill_spaces_oux(data, bf);
}
