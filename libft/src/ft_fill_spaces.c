/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_spaces.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramory-l <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/21 10:50:35 by ramory-l          #+#    #+#             */
/*   Updated: 2019/05/21 11:47:11 by ramory-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	for_mode(char *buffer, char mode, char *str, size_t size)
{
	int i;

	i = 0;
	if (mode == '>')
	{
		while (str[i])
		{
			buffer[i] = str[i];
			i++;
		}
		while (i < size)
		{
			buffer[i] = ' ';
			i++;
		}
	}
}

static void	back_mode(char *buffer, char mode, char *str, size_t size)
{
	int i;
	int j;

	i = 0;
	j = 0;
	if (mode == '<')
	{
		while (i < size - ft_strlen(str))
		{
			buffer[i] = ' ';
			i++;
		}
		while (str[j])
		{
			buffer[i] = str[j];
			i++;
			j++;
		}
	}
}

void	ft_fill_spaces(char *buffer, char mode, char *str, size_t size)
{
	for_mode(buffer, mode, str, size);
	back_mode(buffer, mode, str, size);
}