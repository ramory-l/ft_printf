
#include "ft_printf.h"

int		ft_choose_base(char c)
{
	if (c == 'o')
		return (8);
	if (c == 'x')
		return (16);
	if (c == 'X')
		return (17);
	return (10);
}

int		ft_print_number(unsigned long long int number, char c)
{
	int		base;
	char	*str;

	base = ft_choose_base(c);
	str = ft_itoa_base(number, base);
	while (*str)
		write(1, &*str++, 1);
	return (0);
}
