#include "ft_printf.h"
#include <stdio.h>
#include <math.h>

int	main(void)
{
	// hh = 24
	// h = -1000
	ft_printf("%hhX\n", -1000);
	printf("%hhX\n", -1000);
	return (0);
}
