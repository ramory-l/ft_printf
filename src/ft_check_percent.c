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

static int	ft_find_type_index(const char *format, t_printf *data)
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
		i++;
	}
	data->type = format[index];
	return (index);
}

static void		ft_manage_flags(t_printf *data)
{
	if (data->flags & FLAG_MINUS && data->flags & FLAG_ZERO)
		data->flags &= ~FLAG_ZERO;
	if (data->flags & FLAG_PLUS && data->flags & FLAG_SPACE)
		data->flags &= ~FLAG_SPACE;
	if (data->flags & FLAG_ZERO && data->accuracy > 0)
		data->flags &= ~FLAG_ZERO;
}

const char	*ft_check_ptc(va_list ap, const char *format, t_printf *data)
{
	int type_index;

	type_index = ft_find_type_index(format, data);
	if (type_index == 0)
		return ("");
	data->flags = ft_find_flags(format, type_index);
	data->width = ft_find_width(format, type_index);
	data->accuracy = ft_find_acc(format, type_index, data);
	data->qualifier = ft_find_qualifier(format, type_index);
	ft_manage_flags(data);
	ft_choose_print(ap, format, data);
	return (format + type_index + 1);
}
