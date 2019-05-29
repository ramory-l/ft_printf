/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idunaver <idunaver@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/25 17:26:35 by ramory-l          #+#    #+#             */
/*   Updated: 2019/05/29 20:42:11 by idunaver         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int			ft_intleng(unsigned long long int n)
{
	int			i;
	// unsigned long long int	count;

	i = 0;
	// count = 10;
	// n = n < 0 ? -n : n;
	while (n /= 10)
	{
		// count = count * 10;
		i++;
	}
	return (i + 1);
}

char				*ft_itoa(unsigned long long int n)
{
	int			i;
	int			leng;
	char		*str;
	unsigned long long int	b;

	b = n;
	i = 0;
	leng = ft_intleng(b);
	// if ((b < 0) && (str = ft_memalloc(leng + 2)))
	// {
	// 	str[i] = '-';
	// 	i++;
	// }
	// else if ((str = ft_memalloc(leng + 1)))
	// 	;
	// else
	// 	return (NULL);
	str = ft_memalloc(leng + 1);
	// leng = b < 0 ? leng + 1 : leng;
	// b = b < 0 ? -b : b;
	while (leng-- && str[leng] != '-')
	{
		str[leng] = '0' + (b % 10);
		b /= 10;
	}
	return (str);
}
