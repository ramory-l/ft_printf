#include "ft_printf.h"
#include <stdio.h>
#include <math.h>

int	main(void)
{
	   printf("%llx\n", 9223372036854775808);
	ft_printf("%llx\n", 9223372036854775808);
	return (0);
}
