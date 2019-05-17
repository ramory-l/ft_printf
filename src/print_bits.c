/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_bits.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idunaver <idunaver@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/12 19:15:36 by idunaver          #+#    #+#             */
/*   Updated: 2019/03/13 19:16:43 by idunaver         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void			print_bits(unsigned char octet)
{
	int i;

	i = 7;
	while (i != -1)
	{
		(octet & (1 << i)) == (1 << i) ? write(1, "1", 1) : write(1, "0", 1);
		i--;
	}
}

unsigned char	reverse_bits(unsigned char octet)
{
	unsigned char	t;
	unsigned char	r;
	int				i;

	r = 0;
	i = 7;
	while (i != -1)
	{
		t = octet & 1;
		r = r << 1;
		octet = octet >> 1;
		r = r | t;
		i--;
	}
	return (r);
}

int				main(void)
{
	print_bits(reverse_bits(38));
	return (0);
}
