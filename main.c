#include "ft_printf.h"
#include <stdio.h>

int 	main(void)
{
	double test;
	
	test = 45.45;
	// ft_print_float(test);
	ft_print_double(test);
	printf("\n%.20f\n", test);
	return (0);
}
