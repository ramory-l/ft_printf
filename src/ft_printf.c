#include "ft_printf.h"

void	ft_check_buffer(t_printf *data, t_buffer *bf)
{
	if (bf->s == 511)
	{
		write(1, bf->buffer, bf->s);
		bf->s = 0;
		data->printed += bf->s;
	}
}

int		ft_printf(const char *format, ...)
{
	va_list		ap;
	t_buffer	bf;
	t_printf	data;

	bf.s = 0;
	va_start(ap, format);
	ft_bzero(&data, sizeof(data));
	while (*format)
	{
		if (*format == '%')
			format = ft_check_ptc(ap, format, &data, &bf);
		if (*format && *format != '%')
		{
			bf.buffer[bf.s] = *format;
			format++;
			bf.s++;
			ft_check_buffer(&data, &bf);
		}
	}
	if (bf.s)
	{
		write(1, bf.buffer, bf.s);
		data.printed += bf.s;
	}
	va_end(ap);
	return (data.printed);
}
