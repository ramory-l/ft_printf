#include "ft_printf.h"

static int	ft_choose_base(char c)
{
	if (c == 'o')
		return (8);
	if (c == 'x')
		return (16);
	if (c == 'X')
		return (17);
	return (10);
}

static void	ft_print_signed(va_list ap, t_printf *data)
{
	int di;
	char *number;

	di = va_arg(ap, int);
	if (!*data->size)
		number = ft_itoa_signed(di);
	if (ft_strcmp(data->size, "ll") == 0)
		number = ft_itoa_signed((long long int)di);
	if (ft_strcmp(data->size, "l") == 0)
		number = ft_itoa_signed((long int)di);
	if (ft_strcmp(data->size, "hh") == 0)
		number = ft_itoa_signed((char)di);
	if (ft_strcmp(data->size, "h") == 0)
		number = ft_itoa_signed((short int)di);
	ft_manage_signed(data, number);
	data->printed += ft_strlen(number);
}

static void	ft_print_unsigned(va_list ap, t_printf *data)
{
	int base;
	unsigned int oux_x;
	char *number;

	base = ft_choose_base(data->type);
	oux_x = va_arg(ap, unsigned int);
	if (!*data->size)
		number = ft_itoa_base_unsigned(oux_x, base);
	if (ft_strcmp(data->size, "ll") == 0)
		number = ft_itoa_base_unsigned((unsigned long long int)oux_x, base);
	if (ft_strcmp(data->size, "l") == 0)
		number = ft_itoa_base_unsigned((unsigned long int)oux_x, base);
	if (ft_strcmp(data->size, "hh") == 0)
		number = ft_itoa_base_unsigned((unsigned char)oux_x, base);
	if (ft_strcmp(data->size, "h") == 0)
		number = ft_itoa_base_unsigned((unsigned short int)oux_x, base);
	ft_manage_unsigned(data, number);
	data->printed += ft_strlen(number);
}

static void ft_print_number(va_list ap, const char *format, t_printf *data)
{
	char *number;

	if (data->type == 'd' || data->type == 'i')
		ft_print_signed(ap, data);
	if (data->type == 'o' || data->type == 'u' ||
		data->type == 'x' || data->type == 'X')
		ft_print_unsigned(ap, data);
}

void	ft_print(va_list ap, const char *format, t_printf *data)
{
	if (data->type == 'd' || data->type == 'i' || data->type == 'o' || data->type == 'u' ||
		data->type == 'x' || data->type == 'X')
		ft_print_number(ap, format, data);
}
