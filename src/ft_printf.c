#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	size_t	i;
	int		d;
	char	*s;
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
			if (format[i + 1] == 's')
			{
				s = va_arg(ap, char *);
				ft_putstr(s);
			}
		}
		if (format[i] == '\n')
			write(1, "\n", 1);
		i++;
	}
	va_end(ap);
	return (0);
}
