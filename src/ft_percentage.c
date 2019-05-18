#include "ft_printf.h"

static int	type(char c)
{
	if (c == 'd' || c == 'i' || c == 'o' ||
		c == 'u' || c == 'x' || c == 'X' ||
		c == 'c' || c == 's' || c == 'p')
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

static int	ft_find_percentage(const char *format, t_printf *data)
{
	int i;
	int index;

	i = 1;
	index = 0;
	while (format[i])
	{
		if (format[i] == '%')
			index = i;
		i++;
	}
	return (index);
}

const char	*ft_percentage(va_list ap, const char *format, t_printf *data)
{
	int type_index;

	type_index = ft_find_percentage(format, data);
	if (type_index == 0)
	{
		type_index = ft_find_type_index(format, data);
		if (!type_index)
			return ("");
	}
	else
		data->type = '%';
	data->flags = ft_find_flags(format, type_index);
	data->width = ft_find_width(format, type_index);
	data->accuracy = ft_find_accuracy(format, type_index);
	data->qualifier = ft_find_qualifier(format, type_index);
	ft_print(ap, format, data);
	return (format + type_index + 1);
}
