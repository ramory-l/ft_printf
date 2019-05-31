#include "ft_printf.h"
#include <stdio.h>
#include <float.h>
#include <limits.h>

int 	main(void)
{
	long double longDouble;
	
	longDouble = 2.198;
	printf("%.3Lf\n\n", longDouble);
	ft_longDouble(longDouble, 3);
	return (0);
}