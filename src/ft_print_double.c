#include "ft_printf.h"
#include <stdio.h>

typedef union
{
	long lng;
	double dbl;
}				dbltolng; //double to long

typedef struct	sem_double // sem - sign, exp, mantis
{
	int sign;
	int exp;
	long mantis;
};

typedef struct	t_array
{
	int mantis_arr[1000];
	int len_arr;
	int tmp;
	int base;
}				s_array;

static s_array *ft_bzero_array(s_array *double_a) // заполнение массива нулями
{
	double_a->len_arr = 1000;
	double_a->tmp = 0;
	while(double_a->len_arr--)
	{
		double_a->mantis_arr[double_a->tmp];
		double_a->tmp++;
	}
	double_a->len_arr = 1000;
	double_a->tmp = 0;
	return (double_a);
}

static s_array *ft_mantis_plus_array(s_array *double_a, long mantis) // заполнение массива мантисой с конца
{
	while (mantis)
	{
		double_a->mantis_arr[double_a->len_arr] = mantis % 10;
		mantis /= 10;
		double_a->len_arr--;
	}
	double_a->len_arr = 1000;
	double_a->tmp = 0;
	return (double_a);
}

static void		ft_itoa_double(long mantis, int exp)
{
	s_array *double_a;

	double_a = (s_array*)malloc(sizeof(s_array));
	double_a = ft_bzero_array(double_a);
	double_a = ft_mantis_plus_array(double_a, mantis);
	double_a->base = (exp <= 1075) ? 5 : 2; // определение нормали
	exp = 1075 - exp;
	while (exp)
	{
		
	}
}

void			ft_print_double(double nbr)
{
	struct sem_double dbl;
	dbltolng bits;

	dbl.sign = 0;
	dbl.exp = 0;
	dbl.mantis = 0;
	bits.dbl = nbr;
	dbl.sign = ((bits.lng >> 63) == 0) ? 1 : -1;
	dbl.exp = (int)((bits.lng >> 52) & 0x7ffL);
	dbl.mantis = (dbl.exp == 0) ?
	(bits.lng & 0xfffffffffffffL) << 1 :
	(bits.lng & 0xfffffffffffffL) | 0x10000000000000L;
	if (dbl.sign == -1)
		write(1, "-", 1);
	ft_itoa_double(dbl.mantis, dbl.exp);
	// printf("sign: %d\n", dbl.sign);
	// printf("exp: %d\n", dbl.exp);
	// printf("mantis: %ld\n", dbl.mantis);
}
