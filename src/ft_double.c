#include "ft_printf.h"
#include <stdio.h>

static s_array	*ft_bzero_array(s_array *double_a)
{
	double_a->len_arr = 1000;
	double_a->tmp = 0;
	while (double_a->len_arr--)
	{
		double_a->mantis_arr[double_a->tmp] = 0;
		double_a->tmp++;
	}
	double_a->len_arr = 1000;
	double_a->tmp = 0;
	return (double_a);
}

static s_array	*ft_mantis_plus_array(s_array *double_a, long mantis)
{
	while (mantis)
	{
		double_a->len_arr--;
		double_a->mantis_arr[double_a->len_arr] = mantis % 10;
		mantis /= 10;
	}
	double_a->len_arr = 1000;
	double_a->tmp = 0;
	return (double_a);
}

static s_array	*ft_multandfill(s_array *double_a)
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

static s_array	*ft_more_than_nine(s_array *double_a)
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

static s_array	*ft_mult_column(int exp, s_array *double_a)
{
	while (exp)
	{
		double_a->tmp = 0;
		double_a->len_arr = 1000;
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
	double_a->len_arr = 1000;
	return (double_a);
}

static void		ft_print_double(s_array *double_a, int exp)
{
	char c;

	if (double_a->base == 5)
	{
		while (double_a->temp != 1000)
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
		while (double_a->len_arr != 1000)
		{
			c = double_a->mantis_arr[double_a->len_arr] + '0';
			write(1, &c, 1);
			double_a->len_arr--;
		}
	}
}

static void		ft_itoa_and_print_double(long mantis, int exp)
{
	s_array *double_a;

	double_a = (s_array*)malloc(sizeof(s_array));
	double_a = ft_bzero_array(double_a);
	double_a = ft_mantis_plus_array(double_a, mantis);
	double_a->base = (exp <= 1075) ? 5 : 2;
	exp = 1075 - exp;
	double_a = ft_mult_column(exp, double_a);
	ft_print_double(double_a, exp);
	free(double_a);
}

void			ft_double(double nbr)
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
	ft_itoa_and_print_double(dbl.mantis, dbl.exp);
}
