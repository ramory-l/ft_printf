/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idunaver <idunaver@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/15 17:06:13 by idunaver          #+#    #+#             */
/*   Updated: 2019/06/20 20:47:30 by idunaver         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
#include <math.h>
#include <limits.h>

int	main(void)
{
	// ft_printf("mine %.100Lf\n", 123456.0000000123L);
	// printf("orig %.100Lf\n\n", 123456.0000000123L);
	// ft_printf("mine %.100Lf\n", 123456.123L);
	// printf("orig %.100Lf\n\n", 123456.123L);
	// ft_printf("mine %.100Lf\n", 0.123L);
	// printf("orig %.100Lf\n\n", 0.123L);
	// ft_printf("mine %.100Lf\n", 123456.0L);
	// printf("orig %.100Lf\n\n", 123456.0L);
	// ft_printf("mine %.100Lf\n", 0.0L);
	// printf("orig %.100Lf\n\n", 0.0L);
	// ft_printf("mine %.100f\n", 0.0);
	// printf("orig %.100f\n\n", 0.0);
	// ft_printf("mine %.500f\n", DBL_MIN);
	// printf("orig %.500f\n\n", DBL_MIN);
	// ft_printf("mine %.3f\n", DBL_MAX);
	// printf("orig %.3f\n\n", DBL_MAX);
	printf("orig @moulitest: %5.d %5.0d\n", 0, 0);
	ft_printf("mine @moulitest: %5.d %5.0d\n", 0, 0);
	return (0);
}
