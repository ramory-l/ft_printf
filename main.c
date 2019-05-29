#include "ft_printf.h"
#include <stdio.h>
#include <float.h>
#include <limits.h>

int 	main(void)
{
	long double longDouble;
	
	longDouble = 0.1;
	printf("original long double: %.70Lf\n\n", longDouble);
	ft_longDouble(longDouble);
	return (0);
}