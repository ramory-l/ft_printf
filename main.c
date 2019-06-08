#include "ft_printf.h"
#include <stdio.h>
#include <float.h>
#include <limits.h>
#include <math.h>

int 	main(void)
{
	long double longdouble;
	
	longdouble = 123456789.123456789;
	printf("%.15Lf\n\n", longdouble);
	ft_longdouble(longdouble, 15);
	return (0);
}
