
#include "ft_printf.h"

int		ft_choose_base(char c)
{
	if (c == 'd' || c == 'i')
		return (10);
	if (c == 'o')
		return (8);
	if (c == 'u')
		return (10);
	if (c == 'x')
		return (16);
	if (c == 'X')
		return (17);
	return (-1);
}

int		ft_print_number(unsigned long long int number, char c)
{
	int		base;
	char	*str;

	if ((base = ft_choose_base(c)) == -1)
		return (-1);
	str = ft_itoa_base(number, base);
	while (*str)
		write(1, &*str++, 1);
	return (0);
}
