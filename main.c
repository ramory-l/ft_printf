#include "ft_printf.h"
#include <stdio.h>

int	main(void)
{
	float foobar = 0.9375;
	printf("%;", foobar);
	ft_printf("%i \n %s %%", 5, "Hello");
	return (0);
}
