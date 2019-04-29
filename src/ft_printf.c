#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	va_list ap;

	va_start(ap, format);
	while (*format)
	{
		if (*format == '%')
			ft_manage_percent(format + 1, ap);
		if (*format == '\n')
			write(1, "\n", 1);
		format++;
	}
	va_end(ap);
	return (0);
}
