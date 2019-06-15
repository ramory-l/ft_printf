/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_workwithmantis.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idunaver <idunaver@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/08 19:42:14 by idunaver          #+#    #+#             */
/*   Updated: 2019/06/15 17:03:35 by idunaver         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*ft_fillnulls(int exp, char *fraction, unsigned long mantis)
{
	int		power;
	int		countnull;
	int		lenfractional;
	char	*result;

	lenfractional = 0;
	power = 0;
	countnull = 0;
	lenfractional = ft_strlen(fraction);
	lenfractional--;
	power = ft_minpowerfractional(mantis);
	countnull = 64 - power - exp - lenfractional;
	if (countnull <= 0)
		return (NULL);
	result = (char*)malloc((countnull + 1) * sizeof(char));
	result[countnull] = '\0';
	result = ft_memset(result, '0', countnull);
	return (result);
}

t_arrayint	ft_findingfractionpower(t_longdouble longdouble,
int numofintbits, t_powerbits bitspower)
{
	int			bit;
	t_arrayint	arrayint;

	bitspower = ft_bitspowercontructor(bitspower);
	arrayint = ft_bzeroarrs();
	while (bitspower.numofbits >= 0)
	{
		bit = ((longdouble.mantis & (1UL << bitspower.numofbits)) != 0) ? 1 : 0;
		numofintbits--;
		bitspower.numofbits--;
		if (numofintbits < 0)
		{
			bitspower.power++;
			if (bit == 1)
			{
				bitspower.flag = 1;
				arrayint = ft_bitsandpower(arrayint, bitspower);
			}
			if (bitspower.flag == 1 && (longdouble.mantis << (63 -
			bitspower.numofbits)) != 0)
				arrayint = ft_multlongnumbyaten(arrayint);
		}
	}
	return (arrayint);
}

t_arrayint	ft_findingintpower(t_longdouble longdouble,
int numofintbits, t_powerbits bitspower)
{
	int			numofbits;
	int			bit;
	t_arrayint	arrayint;

	bit = 0;
	numofbits = 63;
	bitspower.base = 2;
	arrayint = ft_bzeroarrs();
	while (numofbits >= 0)
	{
		bit = ((longdouble.mantis & (1UL << numofbits)) != 0) ? 1 : 0;
		numofbits--;
		bitspower.power--;
		if (bitspower.power < 0)
			return (arrayint);
		if (bit == 1)
		{
			arrayint = ft_separationpower(bitspower, arrayint);
			arrayint = ft_summpower(arrayint);
			arrayint = ft_bzerotmparr(arrayint);
		}
		numofintbits--;
	}
	return (arrayint);
}

char		*ft_workwithmantis(t_longdouble longdouble)
{
	t_powerbits		bitspower;
	int				numofintbits;
	t_arrayint		arrayint;
	t_doubletochar	doublechar;
	char			*result;

	numofintbits = longdouble.exp - LDBL_MAX_EXP + 2;
	bitspower.power = numofintbits;
	arrayint = ft_findingintpower(longdouble, numofintbits, bitspower);
	doublechar.inttochar = ft_numtochar(arrayint);
	arrayint = ft_findingfractionpower(longdouble, numofintbits, bitspower);
	doublechar.fractiontochar = ft_numtochar(arrayint);
	if (numofintbits < 0)
		doublechar.nulls = ft_fillnulls(numofintbits,
		doublechar.fractiontochar, longdouble.mantis);
	result = ft_strjoin(*doublechar.inttochar ?
	doublechar.inttochar : "0", ".");
	if (doublechar.nulls)
		result = ft_strjoin(result, doublechar.nulls);
	result = ft_strjoin(result, *doublechar.fractiontochar ?
	doublechar.fractiontochar : "0");
	return (result);
}
