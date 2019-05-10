#include "ft_printf.h"

static int ft_is_printable(unsigned char c)
{
	if ((c >= 32 && c <= 126) || c == '\n')
		return (1);
	return (0);
}

int ft_printf(const char *format, ...)
{
	int i;
	const char *temp;
	va_list ap;
	t_printf data;

	i = 0;
	temp = format;
	ft_bzero(&data, sizeof(data));
	va_start(ap, format);
	if (!format)
		return (0);
	while (*format)
	{
		if (*format == '%')
		{
			if (i != 0)
			{
				write(1, temp, i);
				i = 0;
			}
			format = ft_manage_percentage(ap, format, &data);
			temp = format;
		}
		if (ft_is_printable(*format))
		{
			i++;
			data.printed++;
		}
		if (*format)
			format++;
	}
	if (i != 0)
	{
		write(1, temp, i);
		i = 0;
	}
	va_end(ap);
	return (data.printed);
}
