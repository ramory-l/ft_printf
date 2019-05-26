#include "ft_printf.h"

void	ft_print_char(va_list ap, const char *format, t_printf *data)
{
	char buffer[512];

	buffer[0] = va_arg(ap, int);
	write(1, buffer, 1);
	data->printed += 1;
}