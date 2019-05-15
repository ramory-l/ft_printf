#include "ft_printf.h"

char	ft_find_flags(const char *format, int type_index)
{
	int		i;
	char	flags;

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

char	*ft_find_size(const char *format, int type_index)
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

int		ft_find_width(const char *format, int type_index)
{
	int i;
	int width;

	i = 0;
	width = 0;
	while (i < type_index)
	{
		if (format[i] >= '1' && format[i] <= '9' && format[i - 1] != '.')
			width = ft_atoi(&format[i]);
		i++;
	}
	return (width);
}

int		ft_find_accuracy(const char *format, int type_index)
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
