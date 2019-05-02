#include "ft_printf.h"

static const char	*ft_choose_type(const char *format)
{
	if (ft_strstr(format, "d"))
		return (format = ft_strstr(format, "d"));
	if (ft_strstr(format, "i"))
		return (format = ft_strstr(format, "i"));
	if (ft_strstr(format, "o"))
		return (format = ft_strstr(format, "o"));
	if (ft_strstr(format, "u"))
		return (format = ft_strstr(format, "u"));
	if (ft_strstr(format, "x"))
		return (format = ft_strstr(format, "x"));
	if (ft_strstr(format, "X"))
		return (format = ft_strstr(format, "X"));
	return (format);
}

static int			ft_find_size(const char *format)
{
	if (ft_strstr(format, "ll"))
		return (3);
	if (ft_strstr(format, "l"))
		return (4);
	if (ft_strstr(format, "hh"))
		return (1);
	if (ft_strstr(format, "hh"))
		return (2);
	return (0);
}

static const char	*ft_signed_number(const char *format, va_list ap)
{
	int				qualifier;

	qualifier = ft_find_size(format);
	format = ft_choose_type(format);
	if (*format == 'd' || *format == 'i')
	{
		if (!qualifier)
			ft_print_signed_num(va_arg(ap, int));
		if (qualifier == 1)
			ft_print_signed_num((signed char)va_arg(ap, int));
		if (qualifier == 2)
			ft_print_signed_num((short)va_arg(ap, int));
		if (qualifier == 3)
			ft_print_signed_num((long long)va_arg(ap, int));
		if (qualifier == 4)
			ft_print_signed_num((long)va_arg(ap, int));
	}
	return (format);
}

static const char	*ft_unsigned_number(const char *format, va_list ap)
{
	int				qualifier;

	qualifier = ft_find_size(format);
	format = ft_choose_type(format);
	if (*format == 'o' || *format == 'u' || *format == 'x' || *format == 'X')
	{
		if (!qualifier)
			ft_print_unsigned_num(va_arg(ap, unsigned int), *format);
		if (qualifier == 1)
			ft_print_unsigned_num((unsigned char)va_arg(ap, unsigned int), *format);
		if (qualifier == 2)
			ft_print_unsigned_num((unsigned short)va_arg(ap, unsigned int), *format);
		if (qualifier == 3)
			ft_print_unsigned_num(va_arg(ap, unsigned long long), *format);
		if (qualifier == 4)
			ft_print_unsigned_num(va_arg(ap, unsigned long), *format);
	}
	return (format);
}

const char			*ft_manage_percent(const char *format, va_list ap)
{
	format = ft_signed_number(format, ap);
	format = ft_unsigned_number(format, ap);
	if (*format)
		return (format + 1);
	return (format);
}
