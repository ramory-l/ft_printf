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
	if (data->flags & FLAG_SPACE && !data->sign && data->width == 0)
		data->nbr = ft_fill_spaces(data->nbr, '<', 1);
	if (data->flags & FLAG_SPACE &&
		data->width > 0 && !(data->flags & FLAG_MINUS))
	{
		if (data->width > ft_strlen(data->nbr))
			data->nbr = ft_fill_spaces(data->nbr, '<', data->width - len);
	}
	if (data->flags & FLAG_SPACE && data->width > 0 && data->flags & FLAG_MINUS)
	{
		if (!data->sign)
		{
			data->nbr = ft_fill_spaces(data->nbr, '<', 1);
			data->nbr = ft_fill_spaces(data->nbr, '>', data->width - len - 1);
		}
		else
			data->nbr = ft_fill_spaces(data->nbr, '>', data->width - len);
	}
	if (!(data->flags & FLAG_SPACE) && data->width > 0)
		if (data->width > ft_strlen(data->nbr))
			data->nbr = ft_fill_spaces(data->nbr, '<', data->width - len);
}

static char	*ft_manage_oct(t_printf *data)
{
	char *temp;
	char *new_str;

	if (data->type == 'x')
		temp = "0x";
	else if (data->type == 'X')
		temp = "0X";
	else if (data->type == 'o')
		temp = "0";
	new_str = ft_strjoin(temp, data->nbr);
	free(data->nbr);
	data->nbr = new_str;
	free(new_str);
	return (data->nbr);
}

static void	ft_apply_flags2(t_printf *data)
{
	int len;
	char *temp;
	char *new_str;

	len = ft_strlen(data->nbr);
	if (data->sign)
		len = ft_strlen(data->nbr) - 1;
	if (data->accuracy > len)
		data->nbr = ft_fill_zeros(data->nbr, data->accuracy - len);
	if (data->flags & FLAG_OCT && (data->type == 'x' ||
								data->type == 'X' || data->type == 'o'))
		data->nbr = ft_manage_oct(data);
	if (!data->sign &&
		data->flags & FLAG_PLUS && (data->type == 'd' || data->type == 'i'))
	{
		temp = "+";
		new_str = ft_strjoin(temp, data->nbr);
		if (ft_strcmp(data->nbr, "0") != 0)
			free(data->nbr);
		data->nbr = new_str;
		free(new_str);
	}
}

void		ft_manage_signed(t_printf *data)
{
	ft_manage_flags(data);
	ft_apply_flags1(data);
	ft_apply_flags2(data);
	ft_putstr(data->nbr);
}

void		ft_manage_unsigned(t_printf *data)
{
	ft_manage_flags(data);
	ft_apply_flags1(data);
	ft_apply_flags2(data);
	ft_putstr(data->nbr);
}
