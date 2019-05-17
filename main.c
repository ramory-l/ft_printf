#include "ft_printf.h"
#include <stdio.h>
#include <math.h>

int	main(void)
{
	int d;
	int i;

	d = printf("%+d\n", 10);
	i = ft_printf("%+d\n", 10);


	ft_printf("**%d**%d**\n", 10, 10);
	return (0);
}
