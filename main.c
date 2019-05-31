#include "ft_printf.h"
#include <stdio.h>
#include <float.h>
#include <limits.h>

int 	main(void)
{
	long double longDouble;
	
	longDouble = DBL_MIN;
	printf("%Lf\n\n", longDouble);
	ft_longDouble(longDouble, 6);
	return (0);
}