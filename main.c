#include "ft_printf.h"
#include <stdio.h>
#include <math.h>

int	main(void)
{
	int d = ft_printf("%c\n", 'x');

	ft_printf("%d\n", d);
	return (0);
}
