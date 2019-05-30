#include "ft_printf.h"
#include <stdio.h>
#include <float.h>
#include <limits.h>

int 	main(void)
{
	long double longDouble;
	
	longDouble = 123456789.123456789;
	printf("%Lf\n\n", longDouble);
	ft_longDouble(longDouble, 0);
	return (0);
}