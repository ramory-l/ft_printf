#include "ft_printf.h"

void ft_manage_percent(const char *format, va_list ap)
{
	int sign;
	int diox_x;
	char	flags;

	flags = INIT;
	flags |= FLAG_MINUS;
	if (flags & FLAG_MINUS)
	flags &= ~FLAG_MINUS;
	sign = 0;
	while (*format && (*format == 'd' || *format == 'i' ||
					   *format == 'o' || *format == 'x' || *format == 'X'))
	{
		diox_x = va_arg(ap, int);
		if (diox_x < 0)
		{
			diox_x *= -1;
			sign = 1;
		}
		ft_print_number((unsigned long long int)diox_x, *format);
		format++;
	}
	if (*format && *format == 's')
		ft_putstr(va_arg(ap, char *));
	if (*format && *format == '%')
		write(1, "%", 1);
}
