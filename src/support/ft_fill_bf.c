/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_bf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramory-l <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/02 15:24:51 by ramory-l          #+#    #+#             */
/*   Updated: 2019/06/05 14:13:23 by ramory-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void ft_fill_bf(t_printf *data, t_buffer *bf)
{
	int i;

	i = 0;
	data->len += bf->s;
	if (data->type == 'd' || data->type == 'i')
		data->len += data->sign;
	if (!bf->temp[0])
		return ;
	while (bf->s < data->len)
	{
		if (!i && data->sign && (data->type == 'd' || data->type == 'i'))
		{
			bf->buffer[bf->s] = '-';
			bf->s++;
			ft_check_buffer(data, bf);
		}
		bf->buffer[bf->s] = bf->temp[i];
		bf->s++;
		i++;
		ft_check_buffer(data, bf);
	}
}