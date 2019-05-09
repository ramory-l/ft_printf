#include "ft_printf.h"

static	int type(char c)
{
	if (c == 'd' || c == 'i' || c == 'o' ||
		c == 'u' || c == 'x' || c == 'X')
		return (1);
	return (0);
}

static int	ft_find_type_index(const char **format, t_printf *data)
{
	int index;

	index = 0;
	while (format[0][index] && !type(format[0][index]))
		index++;
	data->type = format[0][index];
	return (index);
}

static char	ft_find_flags(const char **format, int type_index)
{
	int i;
	char flags;

	i = 0;
	flags = INIT;
	while (i < type_index)
	{
		if (format[0][i] == '-')
			flags |= FLAG_MINUS;
		if (format[0][i] == '+')
			flags |= FLAG_PLUS;
		if (format[0][i] == ' ')
			flags |= FLAG_SPACE;
		if (format[0][i] == '#')
			flags |= FLAG_OCT;
		if (format[0][i] == '0')
			flags |= FLAG_ZERO;
		i++;
	}
	return (flags);
}

static	char	*ft_find_size(const char **format, int type_index)
{
	if (ft_strnstr(*format, "ll", type_index))
		return ("ll");
	if (ft_strnstr(*format, "l", type_index))
		return ("l");
	if (ft_strnstr(*format, "hh", type_index))
		return ("hh");
	if (ft_strnstr(*format, "h", type_index))
		return ("h");
	return ("");
}

static int		ft_find_width(const char **format, int type_index)
{
	int i;
	int width;

	i = 0;
	width = 0;
	while (i < type_index)
	{
		if (format[0][i] >= '1' && format[0][i] <= '9')
			width = ft_atoi(&format[0][i]);
		i++;
	}
	return (width);
}

static	int		ft_find_accuracy(const char **format, int type_index)
{
	int i;
	int accuracy;

	i = 0;
	accuracy = 0;
	while (i < type_index)
	{
		if (format[0][i] == '.' && format[0][i + 1] >= '1' && format[0][i + 1] <= '9')
			accuracy = ft_atoi(&format[0][i + 1]);
		i++;
	}
	return (accuracy);
}

void		ft_manage_percentage(const char **format, t_printf *data)
{
	int type_index;

	type_index = ft_find_type_index(format, data);
	data->flags = ft_find_flags(format, type_index);
	data->width = ft_find_width(format, type_index);
	data->accuracy = ft_find_accuracy(format, type_index);
	data->size = ft_find_size(format, type_index);
}