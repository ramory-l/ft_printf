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

static void		ft_print_signed(va_list ap, t_printf *data)
{
	int di;

	di = va_arg(ap, int);
	if (di < 0)
		data->sign = 1;
	if (!data->qualifier)
		data->nbr = ft_itoa_signed(di);
	if (data->qualifier & QUAL_LL)
		data->nbr = ft_itoa_signed((long long int)di);
	if (data->qualifier & QUAL_L)
		data->nbr = ft_itoa_signed((long int)di);
	if (data->qualifier & QUAL_HH)
		data->nbr = ft_itoa_signed((char)di);
	if (data->qualifier & QUAL_H)
		data->nbr = ft_itoa_signed((short int)di);
	ft_manage_signed(data);
	data->printed += ft_strlen(data->nbr);
}

static void		ft_print_unsigned(va_list ap, t_printf *data)
{
	int				base;
	unsigned int	oux_x;
	int				check_sign;

	base = ft_choose_base(data->type);
	oux_x = va_arg(ap, unsigned int);
	check_sign = oux_x;
	if (check_sign < 0)
		data->sign = 1;
	if (!data->qualifier)
		data->nbr = ft_itoa_base_unsigned(oux_x, base);
	if (data->qualifier & QUAL_LL)
		data->nbr = ft_itoa_base_unsigned((unsigned long long int)oux_x, base);
	if (data->qualifier & QUAL_L)
		data->nbr = ft_itoa_base_unsigned((unsigned long int)oux_x, base);
	if (data->qualifier & QUAL_HH)
		data->nbr = ft_itoa_base_unsigned((unsigned char)oux_x, base);
	if (data->qualifier & QUAL_H)
		data->nbr = ft_itoa_base_unsigned((unsigned short int)oux_x, base);
	ft_manage_unsigned(data);
	data->printed += ft_strlen(data->nbr);
}

static void		ft_print_number(va_list ap, const char *format, t_printf *data)
{
	if (data->type == 'd' || data->type == 'i')
		ft_print_signed(ap, data);
	if (data->type == 'o' || data->type == 'u' ||
		data->type == 'x' || data->type == 'X')
		ft_print_unsigned(ap, data);
}

static void		ft_print_string(va_list ap, const char *format, t_printf *data)
{
	char *temp;

	temp = va_arg(ap, char *);
	ft_putstr(temp);
	data->printed += ft_strlen(temp);
}

static void		ft_print_ptr(va_list ap, const char *format, t_printf *data)
{
	data->nbr = ft_itoa_base_unsigned((unsigned long long int)va_arg(ap, void*), 16);
	data->nbr = ft_strjoin("0x", data->nbr);
	ft_putstr(data->nbr);
	data->printed += ft_strlen(data->nbr);
}

void			ft_print(va_list ap, const char *format, t_printf *data)
{
	if (data->type == 'd' || data->type == 'i' ||
		data->type == 'o' || data->type == 'u' ||
		data->type == 'x' || data->type == 'X')
		ft_print_number(ap, format, data);
	if (data->type == 'c')
	{
		ft_putchar((char)va_arg(ap, int));
		data->printed += 1;
	}
	if (data->type == 's')
		ft_print_string(ap, format, data);
	if (data->type == 'p')
		ft_print_ptr(ap, format, data);
}
