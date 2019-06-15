/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dioux_x.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramory-l <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/15 14:00:36 by ramory-l          #+#    #+#             */
/*   Updated: 2019/06/15 14:00:37 by ramory-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		ft_choose_base(char c)
{
	if (c == 'o')
		return (8);
	if (c == 'x' || c == 'p')
		return (16);
	if (c == 'X')
		return (17);
	return (10);
}

static int		ft_check_ptr(va_list ap, t_printf *data, t_buffer *bf, int base)
{
	if (data->type == 'p')
	{
		data->flags |= FLAG_OCT;
		ft_itoa_base((int)va_arg(ap, void *), base, data, bf);
		ft_print_oux_x(data, bf);
		return (1);
	}
	return (0);
}

static void		ft_di(va_list ap, t_printf *data, t_buffer *bf)
{
	long long int di;

	data->sign = 0;
	di = va_arg(ap, long long int);
	if (!data->size)
		di = (int)di;
	if (data->size & SIZE_LL)
		di = (lli)di;
	if (data->size & SIZE_L)
		di = (long)di;
	if (data->size & SIZE_HH)
		di = (char)di;
	if (data->size & SIZE_H)
		di = (short)di;
	if (di < 0)
	{
		data->sign = 1;
		di *= -1;
	}
	ft_itoa_base(di, 10, data, bf);
	ft_print_di(data, bf);
}

static void		ft_oux_x(va_list ap, t_printf *data, t_buffer *bf)
{
	int						base;
	unsigned long long		oux_x;
	long long				check_sign;

	base = ft_choose_base(data->type);
	if (ft_check_ptr(ap, data, bf, base))
		return ;
	oux_x = va_arg(ap, unsigned long long);
	check_sign = oux_x;
	if (check_sign < 0)
		data->sign = 1;
	if (!data->size)
		ft_itoa_base((unsigned)oux_x, base, data, bf);
	if (data->size & SIZE_LL)
		ft_itoa_base((ulli)oux_x, base, data, bf);
	if (data->size & SIZE_L)
		ft_itoa_base((unsigned long)oux_x, base, data, bf);
	if (data->size & SIZE_HH)
		ft_itoa_base((unsigned char)oux_x, base, data, bf);
	if (data->size & SIZE_H)
		ft_itoa_base((unsigned short)oux_x, base, data, bf);
	ft_print_oux_x(data, bf);
}

void			ft_dioux_x(va_list ap, cc *format, t_printf *data, t_buffer *bf)
{
	if (data->type == 'd' || data->type == 'i')
		ft_di(ap, data, bf);
	if (data->type == 'o' || data->type == 'u' ||
		data->type == 'x' || data->type == 'X' ||
		data->type == 'p')
		ft_oux_x(ap, data, bf);
}
