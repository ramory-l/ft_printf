#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	size_t	i;
	int		d;
	va_list ap;

	i = 0;
	va_start(ap, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			if (format[i + 1] == 'd')
			{
				d = va_arg(ap, int);
				ft_print_int(d);
			}
		}
		i++;
	}
	va_end(ap);
	return (0);
}
