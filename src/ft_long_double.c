#include <stdio.h>
#include "ft_printf.h"
#include <float.h> // библиотека с константами

typedef union
{
	unsigned long unsigned_long;
	long double long_double;
}				longdoubletounsignedlong;

struct	long_double
{
	int sign;
	int exp;
	unsigned long mantis;
};

static void			print_bits_unsigned_long(unsigned long octet)
{
	int i;

	i = 63;
	while (i >= 0)
	{
		(octet & (1UL << i)) != 0 ? write(1, "1", 1) : write(1, "0", 1);
		i--;
	}
}

void    ft_magic(int exp)
{
    exp = exp - LDBL_MAX_EXP + 1;
    printf("\nnew_exp: %d\n", exp);
    printf("\nmax_exp: %d\n", LDBL_MAX_EXP);
}

void    ft_long_double(long double number)
{
    longdoubletounsignedlong bits;
    struct long_double longdouble;
    
    bits.long_double = number;
    longdouble.sign = (*(&bits.unsigned_long + 1)) & (1 << 15);
    if (longdouble.sign == -1)
        write(1, "-", 1);
    longdouble.exp = (int)(*(&bits.unsigned_long + 1) & 0x7fffL);
    longdouble.mantis = bits.unsigned_long;
    printf("sign: %d\n", longdouble.sign);
    printf("exp: %d\n", longdouble.exp);
    printf("mantis: %lu\n", longdouble.mantis);
    printf("mantis: %lu\n", bits.unsigned_long);
    // bits.unsigned_long = 5;
    print_bits_unsigned_long(bits.unsigned_long);
    ft_magic(longdouble.exp);
}
