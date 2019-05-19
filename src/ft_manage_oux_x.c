#include "ft_printf.h"

void		ft_manage_oux_x(t_printf *data)
{
	ft_minus_width_rule(data);
	ft_putstr(data->nbr);
}