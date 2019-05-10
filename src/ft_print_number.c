#include "ft_printf.h"

static	void	ft_choose_qualifier(t_printf *data)
{
	
}

void	ft_print_number(va_list ap, const char *format, t_printf *data)
{
	int di;
	int sign;
	char *number;

	sign = 0;
	if (data->type == 'd' || data->type == 'i')
	{
		di = va_arg(ap, int);
		if (di < 0)
		{
			di *= -1;
			sign = 1;
		}
		number = ft_itoa_base_universal(di, 10);
		if (sign)
			write(1, "-", 1);
		ft_putstr(number);
	}
	data->printed += ft_strlen(number) + sign;
}