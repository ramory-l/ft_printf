#include "ft_printf.h"

static int		ft_choose_base(char c)
{
	if (c == 'o')
		return (8);
	if (c == 'x')
		return (16);
	if (c == 'X')
		return (17);
	return (10);
}

static void		ft_di(va_list ap, t_printf *data, t_buffer *bf)
{
	long long int di;

	di = va_arg(ap, long long int);
	if (di < 0)
		data->sign = 1;
	if (!data->size)
		ft_itoa_signed((int)di, bf);
	if (data->size & SIZE_LL)
		ft_itoa_signed((lli)di, bf);
	if (data->size & SIZE_L)
		ft_itoa_signed((long int)di, bf);
	if (data->size & SIZE_HH)
		ft_itoa_signed((char)di, bf);
	if (data->size & SIZE_H)
		ft_itoa_signed((short int)di, bf);
	// ft_manage_di(data);
}

static void		ft_oux_x(va_list ap, t_printf *data, t_buffer *bf)
{
	int						base;
	unsigned long long int	oux_x;
	int						check_sign;

	base = ft_choose_base(data->type);
	oux_x = va_arg(ap, unsigned long long int);
	check_sign = oux_x;
	if (check_sign < 0)
		data->sign = 1;
	if (!data->size)
		ft_itoa_base_unsigned((unsigned int)oux_x, base, data);
	if (data->size & SIZE_LL)
		ft_itoa_base_unsigned((ulli)oux_x, base, data);
	if (data->size & SIZE_L)
		ft_itoa_base_unsigned((unsigned long int)oux_x, base, data);
	if (data->size & SIZE_HH)
		ft_itoa_base_unsigned((unsigned char)oux_x, base, data);
	if (data->size & SIZE_H)
		ft_itoa_base_unsigned((unsigned short int)oux_x, base, data);
	ft_manage_oux_x(data);
}

void		ft_dioux_x(va_list ap, cc *format, t_printf *data, t_buffer *bf)
{
	if (data->type == 'd' || data->type == 'i')
		ft_di(ap, data, bf);
	if (data->type == 'o' || data->type == 'u' ||
		data->type == 'x' || data->type == 'X')
		ft_oux_x(ap, data, bf);
}
