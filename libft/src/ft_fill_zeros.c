/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_zeros.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramory-l <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/15 11:02:35 by ramory-l          #+#    #+#             */
/*   Updated: 2019/05/15 12:19:46 by ramory-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_fill(char *s, int zeros)
{
	int		i;

	i = 0;
	while (i < zeros)
	{
		s[i] = '0';
		i++;
	}
	return (s);
}

char		*ft_fill_zeros(char *s, int zeros)
{
	int		sign;
	char	*temp;
	char	*new_str;

	sign = 0;
	if (s[0] == '-')
		sign = 1;
	temp = (char *)malloc(sizeof(char) * (zeros + 1));
	temp = ft_fill(temp, zeros);
	temp[zeros] = '\0';
	if (sign)
	{
		new_str = ft_strjoin("-", temp);
		free(temp);
		temp = ft_strjoin(new_str, s + 1);
		free(new_str);
		free(s);
		return (temp);
	}
	new_str = ft_strjoin(temp, s);
	free(temp);
	free(s);
	return (new_str);
}