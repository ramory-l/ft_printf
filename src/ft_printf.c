/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idunaver <idunaver@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/15 14:02:42 by ramory-l          #+#    #+#             */
/*   Updated: 2019/06/15 16:55:38 by idunaver         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_init(t_cc *format, t_printf *data, t_buffer *bf)
{
	if (!format)
		return (0);
	bf->s = 0;
	ft_bzero((void *)data, sizeof(*data));
	return (1);
}

int			ft_printf(const char *format, ...)
{
	va_list		ap;
	t_buffer	bf;
	t_printf	data;

	if (!ft_init(format, &data, &bf))
		return (0);
	va_start(ap, format);
	while (*format)
	{
		if (*format == '%')
			format = ft_check_ptc(ap, format, &data, &bf);
		if (*format && *format != '%')
		{
			bf.buffer[bf.s++] = *format;
			format++;
			ft_check_buffer(&data, &bf);
		}
	}
	if (bf.s)
	{
		write(1, bf.buffer, bf.s);
		data.printed += bf.s;
	}
	va_end(ap);
	return (data.printed);
}
