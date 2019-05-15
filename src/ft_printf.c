#include "ft_printf.h"

static int	ft_is_printable(unsigned char c)
{
	if ((c >= 32 && c <= 126) || c == '\n')
		return (1);
	return (0);
}

static void	ft_check(int i, const char *temp)
{
	if (i != 0)
	{
		write(1, temp, i);
		i = 0;
	}
}

int			ft_printf(const char *format, ...)
{
	t_printf	data;

	if (!format)
		return (0);
	ft_bzero(&data, sizeof(data));
	va_start(data.sup.ap, format);
	while (*format)
	{
		if (*format == '%')
		{
			ft_check(data.sup.i, data.sup.temp);
			format = ft_percentage(data.sup.ap, format, &data);
			data.sup.temp = format;
		}
		if (ft_is_printable(*format))
		{
			data.sup.i++;
			data.printed++;
		}
		if (*format)
			format++;
	}
	ft_check(data.sup.i, data.sup.temp);
	va_end(data.sup.ap);
	return (data.printed);
}
