#include "ft_printf.h"

static char		*ft_find_size(const char *format)
{
	char	*new_format;

	if (!(new_format = ft_strstr(format, "hh")))
		return (new_format);
	if (!(new_format = ft_strstr(format, "h")))
		return (new_format);
	if (!(new_format = ft_strstr(format, "ll")))
		return (new_format);
	if (!(new_format = ft_strstr(format, "l")))
		return (new_format);
	return (format);
}

static void		ft_signed_number(const char *format, va_list ap)
{
	long long int	number;
	char			*new_format;

	new_format = ft_find_size(format);
	if (ft_strchr(new_format, 'd') || ft_strchr(new_format, 'i'))
	{
		number = va_arg(ap, long long int);
		ft_print_signed_num(number);
		format++;
	}
}

static void		ft_unsigned_number(const char *format, va_list ap)
{
	unsigned long long int	number;
	char					*new_format;

	new_format = ft_find_size(format);
	if (ft_strchr(new_format, 'o') || ft_strchr(new_format, 'u') ||
		ft_strchr(new_format, 'x') || ft_strchr(new_format, 'X'))
	{
		number = va_arg(ap, unsigned long long int);
		ft_print_unsigned_num(number, *format);
		format++;
	}
}

void			ft_manage_percent(const char *format, va_list ap)
{
	ft_signed_number(format, ap);
	ft_unsigned_number(format, ap);
	if (*format && *format == 's')
		ft_putstr(va_arg(ap, char *));
	if (*format && *format == '%')
		write(1, "%", 1);
}
