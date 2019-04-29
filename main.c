#include "ft_printf.h"
#include <stdio.h>

int 	main(void)
{
	float test;

	test = 12.1115;
	ft_print_fpn(test, 3);
	return (0);
}
