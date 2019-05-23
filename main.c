#include "ft_printf.h"
#include <stdio.h>
#include <math.h>

int	main(void)
{
	int d = ft_printf("%#08x\n", 42);

	printf("%d\n", d);
	return (0);
}
