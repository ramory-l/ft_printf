#include "ft_printf.h"
#include <stdio.h>
#include <math.h>

int	main(void)
{
	int d;
	int i;

	d = ft_printf("%+d\n", 10);
	i = ft_printf("%+d\n", 1000);


	ft_printf("**%d**%d**\n", d, i);
	return (0);
}
