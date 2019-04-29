
#include "ft_printf.h"

void	ft_print_int(int nbr)
{
	char *str;

	str = ft_itoa(nbr);
	while (*str)
		write(1, &*str++, 1);
}
