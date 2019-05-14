#include "ft_printf.h"
#include <stdio.h>

static ss_array	*ft_bzero_array(ss_array *double_a)
{
	double_a->len_arr = 35000;
	double_a->tmp = 0;
	while (double_a->len_arr--)
	{
		double_a->mantis_arr[double_a->tmp] = 0;
		double_a->tmp++;
	}
	double_a->len_arr = 35000;
	double_a->tmp = 0;
	return (double_a);
}

static ss_array	*ft_mantis_plus_array(ss_array *double_a, long long mantis)
{
	while (mantis)
	{
		double_a->len_arr--;
		double_a->mantis_arr[double_a->len_arr] = mantis % 10;
		mantis /= 10;
	}
	double_a->len_arr = 35000;
	double_a->tmp = 0;
	return (double_a);
}

static ss_array	*ft_multandfill(ss_array *double_a)
{
	double_a->mantis_arr[double_a->len_arr] *= double_a->base;
	double_a->mantis_arr[double_a->len_arr] += double_a->tmp;
	if (double_a->mantis_arr[double_a->len_arr] > 9)
	{
		double_a->tmp = double_a->mantis_arr[double_a->len_arr] / 10;
		double_a->mantis_arr[double_a->len_arr] %= 10;
	}
	else
		double_a->tmp = 0;
	return (double_a);
}

static ss_array	*ft_more_than_nine(ss_array *double_a)
{
	if (double_a->tmp > 0)
		double_a = ft_multandfill(double_a);
	else
	{
		double_a->tmp = (double_a->mantis_arr[double_a->len_arr]
		* double_a->base) / 10;
		double_a->mantis_arr[double_a->len_arr] =
		(double_a->mantis_arr[double_a->len_arr] * double_a->base) % 10;
	}
	if (double_a->mantis_arr[double_a->len_arr - 1] == 0)
	{
		double_a->mantis_arr[double_a->len_arr - 1] = double_a->tmp;
		double_a->tmp = 0;
		double_a->len_arr--;
	}
	return (double_a);
}

static ss_array	*ft_mult_column(int exp, ss_array *double_a)
{
	while (exp)
	{
		double_a->tmp = 0;
		double_a->len_arr = 35000;
		while (double_a->len_arr)
		{
			double_a->len_arr--;
			if ((double_a->mantis_arr[double_a->len_arr] * double_a->base) > 9)
				double_a = ft_more_than_nine(double_a);
			else
				double_a = ft_multandfill(double_a);
			if (double_a->mantis_arr[double_a->len_arr])
				double_a->temp = double_a->len_arr;
		}
		exp--;
	}
	double_a->len_arr = 35000;
	return (double_a);
}

static void		ft_print_double(ss_array *double_a, int exp)
{
	char c;

	if (double_a->base == 5)
	{
		while (double_a->temp != 35000)
		{
			if (double_a->temp == (double_a->len_arr - exp))
				write(1, ".", 1);
			c = double_a->mantis_arr[double_a->temp] + '0';
			write(1, &c, 1);
			double_a->temp++;
		}
	}
	else
	{
		while (double_a->len_arr != 35000)
		{
			c = double_a->mantis_arr[double_a->len_arr] + '0';
			write(1, &c, 1);
			double_a->len_arr--;
		}
	}
}

static void		ft_itoa_and_print_longdouble(long long mantis, int exp)
{
	ss_array *double_a;

	double_a = (ss_array*)malloc(sizeof(ss_array));
	double_a = ft_bzero_array(double_a);
	double_a = ft_mantis_plus_array(double_a, mantis);
	double_a->base = exp <= 16446 ? 5 : 2;
	exp = 16446 - exp;
	double_a = ft_mult_column(exp, double_a);
	ft_print_double(double_a, exp);
    free(double_a);
}

void			ft_long_double(long double nbr)
{
	struct sem_long_double longdbl;
	lngdbltouint128 bits;

	longdbl.sign = 0;
	longdbl.exp = 0;
	longdbl.mantis = 0;
	bits.l_dbl = nbr;
	longdbl.sign = (((bits.u_int128 >> (80 - 1)) & 0x1) == 0) ? 1 : -1;
	longdbl.exp = (int)((bits.u_int128 >> (80 - 1 - 15)) & 0x7fffL);
	longdbl.mantis = bits.u_int128 & 0xFFFFFFFFFFFFFFFF;
    printf("sign: %d\n", longdbl.sign);
    printf("exp: %d\n", longdbl.exp);
    printf("mantis: %llu\n", longdbl.mantis);
	if (longdbl.sign == -1)
        write(1, "-", 1);
	ft_itoa_and_print_longdouble(longdbl.mantis, longdbl.exp);
}
