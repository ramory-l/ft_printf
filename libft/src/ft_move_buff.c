/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_buff.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramory-l <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/24 17:33:45 by ramory-l          #+#    #+#             */
/*   Updated: 2019/05/24 22:57:22 by ramory-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_move_buff(char *buffer, int offset)
{
	char	*start;
	char	*end;
	char	*ptr;
	char	temp;

	start = buffer;
	end = buffer;
	while (*end)
		end++;
	ptr = end + offset;
	while (end >= start)
	{
		temp = *end;
		*end = *ptr;
		*ptr = temp;
		ptr--;
		end--;
	}
}