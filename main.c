#include "ft_printf.h"
#include <stdio.h>
#include <float.h>
#include <limits.h>
#include <math.h>

int 	main(void)
{
	long double longDouble;
	
	longDouble = 0.0125;
	printf("%.3Lf\n\n", longDouble);
	ft_longDouble(longDouble, 3);
	return (0);
}

// 0.25 = 0.3? P 1
