#include "ft_printf.h"
#include <stdio.h>
#include <float.h>
#include <limits.h>

int 	main(void)
{
	long double longDouble;
	
	longDouble = LDBL_MIN;
	printf("%.20000Lf\n\n", longDouble);
	ft_longDouble(longDouble);
	return (0);
}