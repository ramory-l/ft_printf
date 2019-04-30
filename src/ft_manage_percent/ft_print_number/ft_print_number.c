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

void	ft_print_signed_num(int number)
{
	char	*num;

	num = ft_itoa_signed(number);
	while (*num)
		write(1, &*num++, 1);
}

void	ft_print_unsigned_num(unsigned long long int number, char c)
{
	int		base;
	char	*num;

	base = ft_choose_base(c);
	num = ft_itoa_base_unsigned(number, base);
	while (*num)
		write(1, &*num++, 1);
}
