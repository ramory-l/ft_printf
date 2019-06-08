/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_long_double.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idunaver <idunaver@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/08 18:37:02 by idunaver          #+#    #+#             */
/*   Updated: 2019/06/08 19:37:26 by idunaver         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static s_arrayint	ft_bzeroarrs(void)
{
	s_arrayint	arrayint;
	int			lenarr;
	int			iarr;

	iarr = 0;
	lenarr = LEN_ARR;
	arrayint.lenarr = LEN_ARR;
	while (lenarr--)
	{
		arrayint.intresult[iarr] = 0;
		arrayint.inttmp[iarr] = 0;
		iarr++;
	}
	arrayint.iarr = 0;
	arrayint.jarr = 0;
	return (arrayint);
}

static int			ft_exponentiation(int power, int number)
{
	int result;

	result = number;
	if (power == 0)
		result = 1;
	else
		while (power-- != 1)
			result *= number;
	return (result);
}

static s_arrayint	ft_multlongnumbyashort(s_arrayint arrayint,
int power, int base)
{
	unsigned long long int	current;
	unsigned long long int	remainder;
	int						jarr;

	jarr = 0;
	remainder = 0;
	current = 0;
	if (arrayint.inttmp[jarr] == 0)
	{
		arrayint.inttmp[jarr] = ft_exponentiation(power, base);
		jarr++;
	}
	while (jarr < arrayint.jarr || remainder)
	{
		if (jarr == arrayint.lenarr)
			return (arrayint);
		current = remainder + arrayint.inttmp[jarr] *
		ft_exponentiation(power, base);
		arrayint.inttmp[jarr] = current % MAX_CELL;
		remainder = current / MAX_CELL;
		jarr++;
	}
	arrayint.jarr = jarr;
	return (arrayint);
}

static s_arrayint	ft_fillarray(s_powerbits bitspower, s_arrayint arrayint)
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

static s_arrayint	ft_separationpower(s_powerbits bitspower,
s_arrayint arrayint)
{
	bitspower.countpower = 0;
	bitspower.remainpower = 0;
	if (bitspower.power >= MAX_POWER)
		bitspower.countpower = bitspower.power / MAX_POWER;
	bitspower.remainpower = bitspower.power % MAX_POWER;
	return (ft_fillarray(bitspower, arrayint));
}

static int			ft_maxindex(s_arrayint arrayint)
{
	return (arrayint.iarr > arrayint.jarr ? arrayint.iarr : arrayint.jarr);
}

static s_arrayint	ft_summpower(s_arrayint arrayint)
{
	unsigned long long int	remminder;
	unsigned long long int	current;
	int						iarr;

	remminder = 0;
	iarr = 0;
	current = 0;
	while (iarr < ft_maxindex(arrayint) || remminder)
	{
		if (iarr == arrayint.lenarr)
			return (arrayint);
		current = arrayint.intresult[iarr] + arrayint.inttmp[iarr] + remminder;
		remminder = current / MAX_CELL;
		if (current)
			arrayint.intresult[iarr] = current % MAX_CELL;
		iarr++;
	}
	arrayint.iarr = iarr;
	return (arrayint);
}

static s_arrayint	ft_bzerotmparr(s_arrayint arrayint)
{
	int iarr;
	int lenarr;

	lenarr = arrayint.jarr;
	iarr = 0;
	while (lenarr--)
	{
		arrayint.inttmp[iarr] = 0;
		iarr++;
	}
	arrayint.jarr = 0;
	return (arrayint);
}

static s_arrayint	ft_findingintpower(s_longdouble longdouble,
int numofintbits, s_powerbits bitspower)
{
	int			numofbits;
	int			bit;
	s_arrayint	arrayint;

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

static s_arrayint	ft_multlongnumbyaten(s_arrayint arrayint)
{
	unsigned long long int	current;
	unsigned long long int	remainder;
	int						iarr;

	iarr = 0;
	remainder = 0;
	current = 0;
	while (iarr < arrayint.iarr || remainder)
	{
		if (iarr == arrayint.lenarr)
			return (arrayint);
		if (arrayint.intresult[iarr] != 0)
			current = remainder + arrayint.intresult[iarr] * 10;
		else
			current = remainder;
		arrayint.intresult[iarr] = current % MAX_CELL;
		remainder = current / MAX_CELL;
		iarr++;
	}
	arrayint.iarr = iarr;
	return (arrayint);
}

static s_arrayint	ft_bitsandpower(s_arrayint arrayint, s_powerbits bitspower)
{
	arrayint = ft_separationpower(bitspower, arrayint);
	arrayint = ft_summpower(arrayint);
	arrayint = ft_bzerotmparr(arrayint);
	return (arrayint);
}

static s_powerbits	ft_bitspowercontructor(s_powerbits bitspower)
{
	bitspower.flag = 0;
	bitspower.numofbits = 63;
	bitspower.base = 5;
	bitspower.power = (bitspower.power < 0) ? bitspower.power * -1 : 0;
	return (bitspower);
}

static s_arrayint	ft_findingfractionpower(s_longdouble longdouble,
int numofintbits, s_powerbits bitspower)
{
	int			bit;
	s_arrayint	arrayint;

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

static char		*ft_numtochar(s_arrayint arrayint)
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

static int	ft_minpowerfractional(unsigned long mantis)
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

static char		*ft_fillnulls(int exp, char *fraction, unsigned long mantis)
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

static char		*ft_workwithmantis(s_longdouble longdouble)
{
	s_powerbits		bitspower;
	int				numofintbits;
	s_arrayint		arrayint;
	s_doubletochar	doublechar;
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

static char		*ft_replace_num_round(int check, long long accuracy,
char *result)
{
	while (accuracy)
	{
		accuracy--;
		check = result[accuracy] - '0';
		check++;
		if (check > 9)
		{
			result[accuracy] = 0 + '0';
			check = result[accuracy] - '0';
		}
		else if (check != 9)
		{
			result[accuracy] = check + '0';
			break ;
		}
	}
	return (result);
}

static char		*ft_if_five_in_fractional(char *result,
int check, long long accuracy)
{
	int			check_null;

	check_null = accuracy + 1;
	while (result[check_null])
	{
		if (result[check_null] != '0')
			break ;
		check_null++;
	}
	if (result[check_null])
		result = ft_replace_num_round(check, accuracy, result);
	return (result);
}

static char		*ft_rounding_fraction(char *result, long long accuracy)
{
	int			check;
	char		*tmp;
	long long	accuracy_tmp;

	check = 0;
	tmp = result;
	accuracy_tmp = accuracy + 1;
	while (*tmp++)
		accuracy_tmp--;
	if (accuracy_tmp < 0)
	{
		check = result[accuracy] - '0';
		if (check == 5)
			result = ft_if_five_in_fractional(result, check, accuracy);
		else if (check > 5)
			result = ft_replace_num_round(check, accuracy, result);
	}
	return (result);
}

static char		*ft_rounding(char *result, long long accuracy)
{
	char	*tmp;
	int		before;
	int		after;
	int		count;
	int		check;

	check = 0;
	count = 0;
	tmp = result;
	while (*tmp != '.')
	{
		tmp++;
		count++;
	}
	tmp++;
	before = *tmp - '0';
	tmp = ft_rounding_fraction(tmp, accuracy);
	after = *tmp - '0';
	if (before > after || (after >= 5 && accuracy == 0))
	{
		check = result[count] - '0';
		result = ft_replace_num_round(check, count, result);
	}
	return (result);
}

static void		ft_printfractional(long long accuracy, char *result)
{
	if (accuracy == 0)
		return ;
	else
	{
		write(1, result, 1);
		result++;
		while (*result && accuracy--)
		{
			write(1, result, 1);
			result++;
		}
		while (accuracy-- > 0)
			write(1, "0", 1);
	}
}

static void		ft_printlongdouble(char *result, long long accuracy, int sign)
{
	int before;
	int after;

	before = *result - '0';
	result = ft_rounding(result, accuracy);
	after = *result - '0';
	if (after == 0 && before != 0)
		result = ft_strjoin("1", result);
	if (sign == 1)
		write(1, "-", 1);
	while (*result != '.')
	{
		write(1, result, 1);
		result++;
	}
	ft_printfractional(accuracy, result);
}

void	ft_longdouble(long double number, long long accuracy)
{
	longdoubletounsignedlong	bits;
	s_longdouble				longdouble;
	char						*result;

	bits.longdouble = number;
	if (accuracy < 0)
		return ;
	longdouble.sign = (*(&bits.unsignedlong + 1)) & (1 << 15) ? 1 : 0;
	longdouble.exp = (int)(*(&bits.unsignedlong + 1) & 0x7fffL);
	longdouble.mantis = bits.unsignedlong;
	result = ft_workwithmantis(longdouble);
	ft_printlongdouble(result, accuracy, longdouble.sign);
	free(result);
}
