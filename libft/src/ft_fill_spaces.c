/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_spaces.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramory-l <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/14 17:42:32 by ramory-l          #+#    #+#             */
/*   Updated: 2019/05/18 23:54:38 by ramory-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_fill(char *s, int spaces)
{
	int		i;

	i = 0;
	while (i < spaces)
	{
		s[i] = ' ';
		i++;
	}
	return (s);
}

char		*ft_fill_spaces(char *s, char mode, int spaces)
{
	char	*temp;
	char	*new_str;

	temp = (char *)malloc(sizeof(char) * (spaces + 1));
	temp = ft_fill(temp, spaces);
	temp[spaces] = '\0';
	if (mode == '<')
		new_str = ft_strjoin(temp, s);
	if (mode == '>')
		new_str = ft_strjoin(s, temp);
	free(temp);
	free(s);
	return (new_str);
}
