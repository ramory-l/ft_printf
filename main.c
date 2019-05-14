#include "ft_printf.h"
#include <stdio.h>

int 	main(void)
{
	double test;
	
	test = 45.45;
	ft_double(test);
	printf("\n%.47f\n", test);
	return (0);
}
