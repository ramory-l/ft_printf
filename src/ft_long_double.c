#include <stdio.h>
#include "ft_printf.h"
#include <float.h> // библиотека с константами

typedef union
{
	__uint128_t uint128t;
	long double long_double;
}				longdoubletouint128;

struct	sem_long_double
{
	int sign;
	int exp;
	long long mantis;
};

void    ft_long_double(long double number)
{
    longdoubletouint128 bits;
    struct sem_long_double longdouble;
    
    bits.long_double = number;
    longdouble.sign = (((bits.uint128t >> (80 - 1)) & 0x1) == 0) ? 1 : -1;
    if (longdouble.sign == -1)
        write(1, "-", 1);
    longdouble.exp = (int)((bits.uint128t >> 64) & 0x7fffL);
    longdouble.mantis = bits.uint128t & 0xFFFFFFFFFFFFFFFF;
    printf("sign: %d\n", longdouble.sign);
    printf("exp: %d\n", longdouble.exp);
    printf("mantis: %llu\n", longdouble.mantis);
}
