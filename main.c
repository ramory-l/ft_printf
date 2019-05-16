#include "ft_printf.h"
#include <stdio.h>
#include <float.h>
#include <limits.h>

int 	main(void)
{
	// float flt;
	double dbl;
	long double l_dbl;
	
	// flt = 11.11;
	// dbl = 0.5;
	l_dbl = 42.0;
	// printf("custom float: \n");
	// ft_double(flt);
	// printf("\noriginal float: \n%.49f\n\n", flt);
	// printf("custom double: \n");
	// ft_double(dbl);
	// printf("\noriginal double: \n%.1500f\n\n", dbl);
	// printf("exp: %d\n", DBL_MAX_EXP);
	// printf("custom long double: \n");
	// ft_long_double(l_dbl);
	// printf("\noriginal long double: \n%.58Lf\n", l_dbl);
	ft_long_double(l_dbl);
	return (0);
}
