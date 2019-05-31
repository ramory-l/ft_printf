#include "ft_printf.h"
#include <stdio.h>
#include <float.h>
#include <limits.h>

int 	main(void)
{
	long double longDouble;
	
	longDouble = 1234.1234;
	printf("orgres: %.20Lf\n\n", longDouble);
	ft_longDouble(longDouble, 10);
	return (0);
}