#include "ft_printf.h"
#include <stdio.h>

int 	main(void)
{
	// float flt;
	// double dbl;
	long double l_dbl;
	
	// flt = 11.11;
	// dbl = 21.21;
	l_dbl = 42.42;
	// printf("custom float: \n");
	// ft_double(flt);
	// printf("\noriginal float: \n%.49f\n\n", flt);
	// printf("custom double: \n");
	// ft_double(dbl);
	// printf("\noriginal double: \n%.48f\n\n", dbl);
	printf("custom long double: \n");
	ft_long_double(l_dbl);
	printf("\noriginal long double: \n%.58Lf\n", l_dbl);
	return (0);
}
