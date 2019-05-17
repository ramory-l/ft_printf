#include "ft_printf.h"
#include <stdio.h>
#include <float.h>
#include <limits.h>

static void			print_bits_unsigned_long(unsigned long octet)
{
	int i;

	i = 63;
	while (i != -1)
	{
		(octet & (1 << i)) == 1 ? write(1, "1", 1) : write(1, "0", 1);
		i--;
	}
}

int 	main(void)
{
	long double l_dbl;
	unsigned long addr;
	
	l_dbl = 818.15625L;
	addr = (unsigned long)l_dbl;
	print_bits_unsigned_long(*(&addr - 1));
	printf("original long double: %.58Lf\n\n", l_dbl);
	ft_long_double(l_dbl);
	return (0);
}
