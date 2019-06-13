/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bitsandpower.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idunaver <idunaver@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/08 20:15:20 by idunaver          #+#    #+#             */
/*   Updated: 2019/06/08 20:23:55 by idunaver         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

s_arrayint	ft_separationpower(s_powerbits bitspower,
s_arrayint arrayint)
{
	bitspower.countpower = 0;
	bitspower.remainpower = 0;
	if (bitspower.power >= MAX_POWER)
		bitspower.countpower = bitspower.power / MAX_POWER;
	bitspower.remainpower = bitspower.power % MAX_POWER;
	return (ft_fillarray(bitspower, arrayint));
}

s_arrayint	ft_bitsandpower(s_arrayint arrayint, s_powerbits bitspower)
{
	arrayint = ft_separationpower(bitspower, arrayint);
	arrayint = ft_summpower(arrayint);
	arrayint = ft_bzerotmparr(arrayint);
	return (arrayint);
}
