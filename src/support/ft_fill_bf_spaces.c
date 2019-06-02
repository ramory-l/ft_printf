/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_bf_spaces.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramory-l <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/02 15:15:29 by ramory-l          #+#    #+#             */
/*   Updated: 2019/06/02 21:20:46 by ramory-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_fill_bf_spaces(t_printf *data, t_buffer *bf)
{
	int	spaces;

	spaces = data->width - data->len + bf->s;
	if (data->flags & FLAG_OCT && !(data->flags & FLAG_MINUS))
	{
		if (data->type == 'x' || data->type == 'X')
			spaces -= 2;
		if (data->type == 'o')
			spaces--;
	}
	while (bf->s < spaces)
	{
		bf->buffer[bf->s] = ' ';
		bf->s++;
	}
}