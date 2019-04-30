/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramory-l <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/29 17:38:01 by ramory-l          #+#    #+#             */
/*   Updated: 2019/04/30 12:30:18 by ramory-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa_base(unsigned long long int value, int base)
{
	int		len;
	int		temp;
	char	*radix;
	char	*number;

	len = 0;
	temp = value;
	if (base == 17)
		radix = "0123456789ABCDEF";
	radix = "0123456789abcdef";
	if (value == 0)
		return ("0");
	while (++len && (value /= base))
		;
	number = (char *)malloc(sizeof(char) * (len + 1));
	number[len] = '\0';
	while (len--)
	{
		number[len] = radix[temp % base];
		temp /= base;
	}
	return (number);
}
