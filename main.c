#include "ft_printf.h"
#include <stdio.h>
#include <float.h>
#include <limits.h>
#include <math.h>

int 	main(void)
{
	long double longDouble;
	
	longDouble = 0.625;
	printf("%.1Lf\n\n", longDouble);
	ft_longDouble(longDouble, 1);
	return (0);
}
