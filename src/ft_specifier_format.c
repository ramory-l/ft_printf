#include "ft_printf.h"

char		ft_find_flags(const char *format, int type_index)
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

static char	ft_find_h(const char *format, int type_index)
{
	int		i;
	int		h;
	char	qualifier;

	i = 0;
	h = 0;
	qualifier = INIT;
	while (i < type_index)
	{
		if (format[i] == 'h')
			h++;
		i++;
	}
	if (h % 2)
	{
		qualifier |= QUAL_H;
		return (qualifier);
	}
	else if (h)
	{
		qualifier |= QUAL_HH;
		return (qualifier);
	}
	return (0);
}

char		ft_find_qualifier(const char *format, int type_index)
{
	int		i;
	int		h;
	char	qualifier;

	i = 0;
	h = 0;
	qualifier = INIT;
	if (ft_strnstr(format, "ll", type_index))
	{
		qualifier |= QUAL_LL;
		return (qualifier);
	}
	if (ft_strnstr(format, "l", type_index))
	{
		qualifier |= QUAL_L;
		return (qualifier);
	}
	return (ft_find_h(format, type_index));
}

int			ft_find_width(const char *format, int type_index)
{
	int i;
	int width;

	i = 0;
	width = 0;
	while (i < type_index)
	{
		if (format[i] >= '1' && format[i] <= '9' && format[i - 1] != '.')
		{
			width = ft_atoi(&format[i]);
			while (ft_isdigit(format[i]))
				i++;
			i--;
		}
		i++;
	}
	return (width);
}

int			ft_find_accuracy(const char *format, int type_index)
{
	int i;
	int accuracy;

	i = 0;
	accuracy = 0;
	while (i < type_index)
	{
		if (format[i] == '.')
		{
			if (format[i + 1] >= '1' && format[i + 1] <= '9')
				accuracy = ft_atoi(&format[i + 1]);
			else
				accuracy = 0;
		}
		i++;
	}
	return (accuracy);
}
