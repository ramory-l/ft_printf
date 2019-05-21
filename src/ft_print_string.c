#include "ft_printf.h"

void		ft_print_string(va_list ap, const char *format, t_printf *data)
{
	data->nbr = va_arg(ap, char *);
	if (!data->nbr)
	{
		ft_putstr("(null)");
		data->printed += 6;
		return ;
	}
	ft_putstr(data->nbr);
	data->printed += ft_strlen(data->nbr);
}