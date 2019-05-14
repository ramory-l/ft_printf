#include "ft_printf.h"

static int	type(char c)
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

const char	*ft_percentage(va_list ap, const char *format, t_printf *data)
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
