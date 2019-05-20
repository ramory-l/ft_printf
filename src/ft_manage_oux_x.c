#include "ft_printf.h"

static void	ft_zero(t_printf *data)
{
	data->len = ft_strlen(data->nbr);
	if (data->flags & FLAG_ZERO && data->width > data->len)
	{
		if (data->flags & FLAG_OCT)
		{
			data->nbr = ft_fill_zeros(data->nbr, data->width - data->len - 2);
			return ;
		}
		data->nbr = ft_fill_zeros(data->nbr, data->width - data->len);
	}
}

static void	ft_oct(t_printf *data)
{
	char *temp;
	char *new_str;

	if (data->type == 'x' || data->type == 'X')
		if (!ft_strcmp(data->nbr, "0"))
		{
			if (data->acc && !data->accuracy)
				data->nbr = "";
			return ;
		}
	if (data->flags & FLAG_OCT)
	{
		if (!ft_strcmp(data->nbr, "0"))
		{
			if (data->acc && !data->accuracy)
				data->nbr = "";
			return ;
		}
		if (data->type == 'x')
			temp = "0x";
		else if (data->type == 'X')
			temp = "0X";
		new_str = ft_strjoin(temp, data->nbr);
		free(data->nbr);
		data->nbr = new_str;
	}
}

void		ft_manage_oux_x(t_printf *data)
{
	ft_zero(data);
	ft_oct(data);
	ft_minus_width_rule(data);
	ft_putstr(data->nbr);
}