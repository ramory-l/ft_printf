#include "ft_printf.h"
#include <stdio.h>
#include <float.h>
#include <limits.h>

int 	main(void)
{
	long double longDouble;
	
	longDouble = DBL_MIN;
	printf("original long double: %.1500Lf\n\n", longDouble);
	ft_longDouble(longDouble);
	return (0);
}