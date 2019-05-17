#include "ft_printf.h"
#include <stdio.h>
#include <math.h>

int	main(void)
{
	char *ptr = 0;

	char *Hekko = "Hello";
	printf("%p\n", ptr);
	ft_printf("%p\n", ptr);
	return (0);
}
