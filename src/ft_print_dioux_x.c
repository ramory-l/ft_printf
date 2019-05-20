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

static void		ft_print_di(va_list ap, t_printf *data)
{
	long long int di;

	di = va_arg(ap, long long int);
	if (di < 0)
		data->sign = 1;
	if (!data->size)
		data->nbr = ft_itoa_signed((int)di);
	if (data->size & SIZE_LL)
		data->nbr = ft_itoa_signed((long long int)di);
	if (data->size & SIZE_L)
		data->nbr = ft_itoa_signed((long int)di);
	if (data->size & SIZE_HH)
		data->nbr = ft_itoa_signed((char)di);
	if (data->size & SIZE_H)
		data->nbr = ft_itoa_signed((short int)di);
	ft_manage_di(data);
	data->printed += ft_strlen(data->nbr);
}

static void		ft_print_oux_x(va_list ap, t_printf *data)
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
		data->nbr = ft_itoa_base_unsigned((unsigned int)oux_x, base);
	if (data->size & SIZE_LL)
		data->nbr = ft_itoa_base_unsigned((unsigned long long int)oux_x, base);
	if (data->size & SIZE_L)
		data->nbr = ft_itoa_base_unsigned((unsigned long int)oux_x, base);
	if (data->size & SIZE_HH)
		data->nbr = ft_itoa_base_unsigned((unsigned char)oux_x, base);
	if (data->size & SIZE_H)
		data->nbr = ft_itoa_base_unsigned((unsigned short int)oux_x, base);
	ft_manage_oux_x(data);
	data->printed += ft_strlen(data->nbr);
}

void		ft_print_dioux_x(va_list ap, const char *format, t_printf *data)
{
	if (data->type == 'd' || data->type == 'i')
		ft_print_di(ap, data);
	if (data->type == 'o' || data->type == 'u' ||
		data->type == 'x' || data->type == 'X')
		ft_print_oux_x(ap, data);
}