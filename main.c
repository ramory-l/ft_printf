#include "ft_printf.h"
#include <stdio.h>

int	main(void)
{
	printf("%i \n %s %%", 5, "Hello");
	ft_printf("%; i \n %s %%", 5, "Hello");
	return (0);
}
