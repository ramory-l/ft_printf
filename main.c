#include "ft_printf.h"
#include <stdio.h>
#include <math.h>

int	main(void)
{
	// ft_printf("%5d\n", 42);
	int dd = printf("orig dasdds  dasda\n");
	int d = ft_printf("my dasdds  dasda\n");

	ft_printf("my %d\n", dd);
	printf("orig %d\n", dd);
	return (0);
}
