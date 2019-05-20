#include "ft_printf.h"

static int	type(char c)
{
	if (c == 'd' || c == 'i' || c == 'o' ||
		c == 'u' || c == 'x' || c == 'X' ||
		c == 'c' || c == 's' || c == 'p' ||
		c == '%')
		return (1);
	return (0);
}

static void	ft_check_flag(const char *format, t_printf *data)
{
	if (*format == '-')
		data->flags |= FLAG_MINUS;
	if (*format == '+')
		data->flags |= FLAG_PLUS;
	if (*format == ' ')
		data->flags |= FLAG_SPACE;
	if (*format == '#')
		data->flags |= FLAG_OCT;
	if (*format == '0' && !ft_isdigit(*(format - 1)) && *(format - 1) != '.')
		data->flags |= FLAG_ZERO;
}

static const char	*ft_check_width(const char *format, t_printf *data)
{
	if (*format >= '1' && *format <= '9' && *(format - 1) != '.')
	{
		data->width = ft_atoi(format);
		while (ft_isdigit(*format))
			format++;
		format -= 2;
	}
	return (format);
}

static void ft_check_acc(const char *format, t_printf *data)
{
	if (*format == '.')
	{
		data->acc = 1;
		if (*(format + 1) >= '1' && *(format + 1) <= '9')
			data->accuracy = ft_atoi(format + 1);
	}
}

static void	ft_check_size(t_printf *data)
{
	if (data->l_count)
	{
		if (data->l_count % 2)
			data->size |= SIZE_L;
		else
			data->size |= SIZE_LL;
		return ;
	}
	if (data->h_count)
	{
		if (data->h_count % 2)
			data->size |= SIZE_H;
		else
			data->size |= SIZE_HH;
	}
}

int	ft_specifier_format(const char *format, t_printf *data)
{
	int i;
	int index;

	i = 1;
	index = 0;
	while (format[i])
	{
		if (type(format[i]))
		{
			index = i;
			break ;
		}
		ft_check_flag(&format[i], data);
		format = ft_check_width(&format[i], data);
		if (format[i] == 'l')
			data->l_count++;
		if (format[i] == 'h')
			data->h_count++;
		i++;
	}
	ft_check_size(data);
	data->type = format[index];
	return (index);
}
