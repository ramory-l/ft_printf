#include "ft_printf.h"
#include <stdio.h>
#include <float.h>
#include <limits.h>

int 	main(void)
{
	long double longDouble;
	
	longDouble = 555.555;
	printf("%.8Lf\n\n", longDouble);
	ft_longDouble(longDouble, 8);
	return (0);
}