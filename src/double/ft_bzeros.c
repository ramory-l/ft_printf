/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzeros.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idunaver <idunaver@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/08 20:11:00 by idunaver          #+#    #+#             */
/*   Updated: 2019/06/15 16:44:46 by idunaver         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_arrayint	ft_bzeroarrs(void)
{
	t_arrayint	arrayint;
	int			lenarr;
	int			iarr;

	iarr = 0;
	lenarr = LEN_ARR;
	arrayint.lenarr = LEN_ARR;
	while (lenarr--)
	{
		arrayint.intresult[iarr] = 0;
		arrayint.inttmp[iarr] = 0;
		iarr++;
	}
	arrayint.iarr = 0;
	arrayint.jarr = 0;
	return (arrayint);
}

t_arrayint	ft_bzerotmparr(t_arrayint arrayint)
{
	int iarr;
	int lenarr;

	lenarr = arrayint.jarr;
	iarr = 0;
	while (lenarr--)
	{
		arrayint.inttmp[iarr] = 0;
		iarr++;
	}
	arrayint.jarr = 0;
	return (arrayint);
}
