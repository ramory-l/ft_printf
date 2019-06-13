/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_long_double.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tulupovArtem <tulupovArtem@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/08 18:37:02 by idunaver          #+#    #+#             */
/*   Updated: 2019/06/13 13:49:19 by tulupovArte      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

s_arrayint	ft_fillarray(s_powerbits bitspower, s_arrayint arrayint)
{
	if (bitspower.countpower)
	{
		while (bitspower.countpower--)
			arrayint = ft_multlongnumbyashort(arrayint,
			MAX_POWER, bitspower.base);
	}
	if (bitspower.remainpower || (!bitspower.remainpower
	&& !bitspower.countpower))
		arrayint = ft_multlongnumbyashort(arrayint,
		bitspower.remainpower, bitspower.base);
	return (arrayint);
}

s_powerbits	ft_bitspowercontructor(s_powerbits bitspower)
{
	bitspower.flag = 0;
	bitspower.numofbits = 63;
	bitspower.base = 5;
	bitspower.power = (bitspower.power < 0) ? bitspower.power * -1 : 0;
	return (bitspower);
}

char		*ft_numtochar(s_arrayint arrayint)
{
	char	*result;
	char	*tmp;
	int		i;
	int		lenarr;
	char	*nulls;

	i = --arrayint.iarr;
	result = "\0";
	while (i >= 0)
	{
		tmp = ft_itoa(arrayint.intresult[i]);
		lenarr = ft_strlen(tmp);
		if (lenarr != 8 && *result)
		{
			nulls = (char*)malloc((8 - lenarr + 1) * sizeof(char));
			nulls[8 - lenarr] = '\0';
			nulls = ft_memset(nulls, '0', 8 - lenarr);
			tmp = ft_strjoin(nulls, tmp);
			free(nulls);
		}
		result = ft_strjoin(result, tmp);
		i--;
	}
	return (result);
}

int			ft_minpowerfractional(unsigned long mantis)
{
	int	bitindex;
	int	power;
	int	bit;

	bit = 0;
	power = 0;
	bitindex = 0;
	while (bitindex < 64)
	{
		bit = (mantis & (1UL << bitindex)) != 0 ? 1 : 0;
		if (bit == 1)
		{
			power = bitindex;
			break ;
		}
		bitindex++;
	}
	return (power);
}

void		ft_longdouble(va_list ap, t_printf *data, t_buffer *bf)
{
	longdoubletounsignedlong	bits;
	s_longdouble				longdouble;
	char						*result;
	long double					number;

	number = va_arg(ap, long double);
	if (!data->acc)
		data->accuracy = 6;
	bits.longdouble = number;
	if (data->accuracy < 0)
		return ;
	longdouble.sign = (*(&bits.unsignedlong + 1)) & (1 << 15) ? 1 : 0;
	longdouble.exp = (int)(*(&bits.unsignedlong + 1) & 0x7fffL);
	longdouble.mantis = bits.unsignedlong;
	result = ft_workwithmantis(longdouble);
	ft_printlongdouble(result, data, longdouble.sign, bf);
	free(result);
}
