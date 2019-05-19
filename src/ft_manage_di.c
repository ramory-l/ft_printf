#include "ft_printf.h"

void		ft_manage_di(t_printf *data)
{
	ft_minus_width_rule(data);
	ft_putstr(data->nbr);
}