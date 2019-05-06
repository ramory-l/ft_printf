#include "ft_printf.h"
#include <stdio.h>

int 	main(void)
{
	double test;

	test = 45.45;
	ft_print_fpn(test);
	printf("\n%.20f\n", test);
	return (0);
}
