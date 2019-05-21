#include "ft_printf.h"

void	ft_print_char(va_list ap, const char *format, t_printf *data)
{
	data->nbr = ft_strnew(1);
	data->nbr[0] = va_arg(ap, int);
	ft_putstr(data->nbr);
	data->printed += 1;
}