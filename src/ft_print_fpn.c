
#include "ft_printf.h"
#include <stdio.h>

typedef union
{
	int integer;
	float fl;
} 			number;

void		ft_magic(int mantis, int exp)
{
	int normal;
	int mantis_arr[1000];
	int len;
	int tmp;
	int	temp;
	int tmp_exp;
	char c;

	tmp = 0;
	len = 1000;
	while (len--) // заполнение массива нулями
	{
		mantis_arr[tmp] = 0;
		tmp++;
	}
	tmp = 0;
	len = 1000;
	if (exp <= 150)
	{
		normal = 5;
		exp = 150 - exp;
		tmp_exp = exp;
	}
	else
	{
		exp = 150 - exp;
		normal = 2;
	}
	while (mantis) // заполнение массива мантисой с конца
	{
		len--;
		mantis_arr[len] = mantis % 10;
		mantis = mantis / 10;
	}
	len = 1000;
	while (exp) // умножнение столбиком
	{
		tmp = 0;
		len = 1000;
		while (len)
		{
			len--;
			if ((mantis_arr[len] * normal) > 9)
			{
				
				if (tmp > 0) // если мы что-то держим в "памяти"
				{
					mantis_arr[len] = mantis_arr[len] * normal;
					mantis_arr[len] = mantis_arr[len] + tmp;
					if (mantis_arr[len] > 9)
					{
						tmp = mantis_arr[len] / 10;
						mantis_arr[len] %= 10;
					}
					else
						tmp = 0;
				}
				else
				{
					tmp = (mantis_arr[len] * normal) / 10; // второй разряд в "памяти"
					mantis_arr[len] = (mantis_arr[len] * normal) % 10; // перезапись нашего числа
				}
				if (mantis_arr[len - 1] == 0) // если второй разрд в памяти, а следующий разряд мантисы равен 0
				{
					mantis_arr[len - 1] = tmp;
					tmp = 0;
					len--;
				}
			}
			else
			{
				mantis_arr[len] = mantis_arr[len] * normal;
				mantis_arr[len] = mantis_arr[len] + tmp;
				if (mantis_arr[len] > 9)
				{
					tmp = mantis_arr[len] / 10;
					mantis_arr[len] %= 10;
				}
				else
					tmp = 0;
			}
			if (mantis_arr[len])
				temp = len;
		}
		exp--;
	}
	len = 1000;
	if (normal == 5) // проверка на точку
	{
		while (temp != 1000)
		{
			
			if (temp == (len - tmp_exp))
				write(1, ".", 1);
			c = mantis_arr[temp] + '0';
			write(1, &c, 1);
			temp++;
			//tmp_exp--;
		}
	}
	else
	{
		while (len != 1000)
		{
			c = mantis_arr[len] + '0';
			write(1, &c, 1);
			len--;
		}
	}
}

void		ft_print_fpn(double nbr)
{
	int sign;
	int exp;
	int mantis;
	number bits;

	sign = 0;
	exp = 0;
	mantis = 0;

	bits.fl = nbr;

	sign = ((bits.integer >> 31) == 0) ? 1 : -1;
	exp = ((bits.integer >> 23) & 0xff);
	mantis = (exp == 0) ? (bits.integer & 0x7fffff) << 1 :
	(bits.integer & 0x7fffff) | 0x800000;
	printf("exp: %d\n", exp);
	printf("sign: %d\n", sign);
	printf("mantis: %d\n", mantis);
	if (sign == -1)
		write(1, "-", 1);
	ft_magic(mantis, exp);
}
