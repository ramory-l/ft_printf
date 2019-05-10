#include "ft_printf.h"
#include <stdio.h>
#include <math.h>

int	main(void)
{
	int d = ft_printf("%d\n", -1000);
	printf("%d", d);
	return (0);
}
