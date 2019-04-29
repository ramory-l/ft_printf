/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramory-l <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/29 17:38:01 by ramory-l          #+#    #+#             */
/*   Updated: 2019/04/29 18:24:54 by ramory-l         ###   ########.fr       */
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
	radix = "0123456789ABCDEF";
	if (value == 0)
		return ("0");
	while (value /= base)
		len++;
	number = (char *)malloc(sizeof(char) * (len + 1));
	
	return (NULL);
}
