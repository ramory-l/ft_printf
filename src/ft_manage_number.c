#include "ft_printf.h"

static void	ft_ignore_flags(t_printf *data)
{
	if (data->flags & FLAG_MINUS && data->flags & FLAG_ZERO)
		data->flags &= ~FLAG_ZERO;
	if (data->flags & FLAG_PLUS && data->flags & FLAG_SPACE)
		data->flags &= ~FLAG_SPACE;
}

void	ft_manage_signed(t_printf *data, char *number)
{
	ft_ignore_flags(data);
	ft_putstr(number);
}

void	ft_manage_unsigned(t_printf *data, char *number)
{
	ft_putstr(number);
}
