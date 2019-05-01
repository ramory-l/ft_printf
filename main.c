#include "ft_printf.h"
#include <stdio.h>

int	main(void)
{
	long int a = 3214512512;
	printf("%h ld\n", a);
	ft_printf("%h ld\n", a);
	return (0);
}
