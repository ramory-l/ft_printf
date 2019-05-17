#include "ft_printf.h"
#include <stdio.h>
#include <math.h>

int	main(void)
{
	int d;
	int i;

	d = ft_printf("%p\n", 100);
	i = ft_printf("%p\n", 1000);


	ft_printf("**%d**%d**\n", d, i);
	return (0);
}
