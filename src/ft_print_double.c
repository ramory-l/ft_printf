/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_double.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idunaver <idunaver@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/08 20:02:12 by idunaver          #+#    #+#             */
/*   Updated: 2019/06/08 20:07:40 by idunaver         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_printfractional(long long accuracy, char *result)
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

void		ft_printlongdouble(char *result, long long accuracy, int sign)
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
