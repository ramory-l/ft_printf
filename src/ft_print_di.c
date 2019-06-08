#include "ft_printf.h"

void	ft_print_di(t_printf *data, t_buffer *bf)
{
	if (data->sign)
	{
		bf->buffer[bf->s] = '-';
		bf->s++;
		ft_check_buffer(data, bf);
	}
	ft_fill_bf(data, bf);
}
