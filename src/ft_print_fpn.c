
#include "ft_printf.h"

static void ft_rounding(double nbr)
{
	unsigned int end_nbr;
	unsigned int last_nbr;
	char c;

	end_nbr = nbr;
	end_nbr = end_nbr % 10;
	last_nbr = nbr * 10;
	last_nbr = last_nbr % 10;
	if (last_nbr >= 5)
		end_nbr += end_nbr;
	c = end_nbr + '0';
	write(1, &c, 1);
}

static void	ft_end_nbr(double nbr, unsigned int nbr_sign)
{
	unsigned int end_nbr;
	unsigned int count;
	char c;

	end_nbr = 0;
	if (nbr_sign == 0)
		count = 6;
	else if (nbr_sign > 308)
		return ;
	else
		count = nbr_sign;
	while (count)
	{
		end_nbr = nbr * 10;
		c = (end_nbr % 10) + '0';
		nbr = nbr * 10;
		if (count != 1)
			write(1, &c, 1);
		else
			ft_rounding(nbr);
		count--;
	}
}

void		ft_print_fpn(double nbr, unsigned int nbr_sign)
{
	unsigned int begin_nbr;

	begin_nbr = 0;
	if (nbr < 0)
	{
		nbr = nbr * (-1);
		begin_nbr = (unsigned int)nbr;
		write(1, "-", 1);
	}
	else
		begin_nbr = (unsigned int)nbr;
	ft_print_int(begin_nbr);
	write(1, ".", 1);
	ft_end_nbr(nbr, nbr_sign);
}
