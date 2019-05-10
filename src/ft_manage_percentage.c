#include "ft_printf.h"

static	int type(char c)
{
	if (c == 'd' || c == 'i' || c == 'o' ||
		c == 'u' || c == 'x' || c == 'X')
		return (1);
	return (0);
}

static int	ft_find_type_index(const char *format, t_printf *data)
{
	int i;
	int index;

	i = 0;
	index = 0;
	while (format[i])
	{
		if (type(format[i]))
		{
			index = i;
			break ;
		}
		i++;
	}
	data->type = format[index];
	return (index);
}

static char	ft_find_flags(const char *format, int type_index)
{
	int i;
	char flags;

	i = 0;
	flags = INIT;
	while (i < type_index)
	{
		if (format[i] == '-')
			flags |= FLAG_MINUS;
		if (format[i] == '+')
			flags |= FLAG_PLUS;
		if (format[i] == ' ')
			flags |= FLAG_SPACE;
		if (format[i] == '#')
			flags |= FLAG_OCT;
		if (format[i] == '0')
			flags |= FLAG_ZERO;
		i++;
	}
	return (flags);
}

static	char	*ft_find_size(const char *format, int type_index)
{
	int i;
	int h;

	i = 0;
	h = 0;
	if (ft_strnstr(format, "ll", type_index))
		return ("ll");
	if (ft_strnstr(format, "l", type_index))
		return ("l");
	while (i < type_index)
	{
		if (format[i] == 'h')
			h++;
		i++;
	}
	if (h % 2)
		return ("h");
	else
		return ("hh");
	return ("");
}

static int		ft_find_width(const char *format, int type_index)
{
	int i;
	int width;

	i = 0;
	width = 0;
	while (i < type_index)
	{
		if (format[i] >= '1' && format[i] <= '9')
			width = ft_atoi(&format[i]);
		i++;
	}
	return (width);
}

static	int		ft_find_accuracy(const char *format, int type_index)
{
	int i;
	int accuracy;

	i = 0;
	accuracy = 0;
	while (i < type_index)
	{
		if (format[i] == '.' && format[i + 1] >= '1' && format[i + 1] <= '9')
			accuracy = ft_atoi(&format[i + 1]);
		i++;
	}
	return (accuracy);
}

const	char	*ft_manage_percentage(va_list ap, const char *format, t_printf *data)
{
	int type_index;

	type_index = ft_find_type_index(format, data);
	if (type_index == 0)
	{
		format++;
		if (ft_strchr(format, '%'))
			return (format = ft_strchr(format, '%'));
		return ("");
	}
	data->flags = ft_find_flags(format, type_index);
	data->width = ft_find_width(format, type_index);
	data->accuracy = ft_find_accuracy(format, type_index);
	data->size = ft_find_size(format, type_index);
	ft_print(ap, format, data);
	return (format + type_index + 1);
}