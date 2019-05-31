#include "ft_printf.h"
#include <stdio.h>
#include <float.h>
#include <limits.h>

int 	main(void)
{
	long double longDouble;
	
	longDouble = 6.99999999999999;
	printf("%.5Lf\n\n", longDouble);
	ft_longDouble(longDouble, 5);
	return (0);
}