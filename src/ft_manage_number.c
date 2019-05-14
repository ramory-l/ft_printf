#include "ft_printf.h"

static void	ft_manage_flags(t_printf *data)
{
	if (data->flags & FLAG_MINUS && data->flags & FLAG_ZERO)
		data->flags &= ~FLAG_ZERO;
	if (data->flags & FLAG_PLUS && data->flags & FLAG_SPACE)
		data->flags &= ~FLAG_SPACE;
	if (data->flags & FLAG_ZERO && data->accuracy > 0)
		data->flags &= ~FLAG_ZERO;
}

static void	ft_apply_flags1(t_printf *data)
{
	int len;

	len = ft_strlen(data->nbr);
	if (data->flags & FLAG_SPACE && data->nbr[0] != '-' && data->width == 0)
		data->nbr = ft_fill_spaces(data->nbr, '<', 1);
	if (data->flags & FLAG_SPACE &&
		data->width > 0 && !(data->flags & FLAG_MINUS))
	{
		if (data->width > ft_strlen(data->nbr))
			data->nbr = ft_fill_spaces(data->nbr, '<', data->width - len);
	}
	if (data->flags & FLAG_SPACE && data->width > 0 && data->flags & FLAG_MINUS)
	{
		if (data->nbr[0] != '-')
		{
			data->nbr = ft_fill_spaces(data->nbr, '<', 1);
			data->nbr = ft_fill_spaces(data->nbr, '>', data->width - len - 1);
		}
		else
			data->nbr = ft_fill_spaces(data->nbr, '>', data->width - len);
	}
	if (!(data->flags & FLAG_SPACE) && data->width > 0)
		if (data->width > ft_strlen(data->nbr))
			data->nbr = ft_fill_spaces(data->nbr, '>', data->width - len);
}

void		ft_manage_signed(t_printf *data)
{
	ft_manage_flags(data);
	ft_apply_flags1(data);
	ft_putstr(data->nbr);
}

void		ft_manage_unsigned(t_printf *data)
{
	ft_manage_flags(data);
	ft_apply_flags1(data);
	ft_putstr(data->nbr);
}
