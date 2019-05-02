#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	va_list ap;

	va_start(ap, format);
	while (*format)
	{
		if (*format == '%')
			format = ft_manage_percent(format + 1, ap);
		if (*format == '\n')
			write(1, "\n", 1);
		if (*format >= 32 && *format <= 126)
			write(1, format, 1);
		if (*format)
			format++;
	}
	va_end(ap);
	return (0);
}
