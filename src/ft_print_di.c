#include "ft_printf.h"

static void ft_acc_width_no_minus(t_printf *data, t_buffer *bf)
{
	int i;

	i = data->accuracy;
	while (i < data->width)
	{
		bf->buffer[bf->s] = ' ';
		bf->s++;
		i++;
		ft_check_buffer(data, bf);
	}
	ft_add_sign(data, bf);
	ft_fill_zeroes_di(data, bf);
	ft_fill_bf(data, bf);
}

static void ft_acc_width(t_printf *data, t_buffer *bf)
{
	int i;

	if (data->flags & FLAG_PLUS || data->sign)
		data->width--;
	if (data->flags & FLAG_MINUS)
	{
		ft_add_sign(data, bf);
		ft_fill_zeroes_di(data, bf);
		ft_fill_bf(data, bf);
		i = data->accuracy;
		while (i < data->width)
		{
			bf->buffer[bf->s] = ' ';
			bf->s++;
			i++;
			ft_check_buffer(data, bf);
		}
	}
	else
		ft_acc_width_no_minus(data, bf);
}

static void ft_width(t_printf *data, t_buffer *bf)
{
	if (data->flags & FLAG_PLUS || data->sign)
		data->width--;
	if (data->flags & FLAG_MINUS)
	{
		if (data->sign)
			data->width++;
		ft_add_sign(data, bf);
		ft_fill_bf(data, bf);
		ft_fill_spaces_di(data, bf);
	}
	else
	{
		if (data->flags & FLAG_ZERO)
		{
			ft_add_sign(data, bf);
			ft_fill_spaces_di(data, bf);
			ft_fill_bf(data, bf);
		}
		else
		{
			ft_fill_spaces_di(data, bf);
			ft_add_sign(data, bf);
			ft_fill_bf(data, bf);
		}
	}
}

static int	_ft_width_acc(t_printf *data, t_buffer *bf)
{
	if (data->accuracy > data->len)
	{
		if (data->width > data->accuracy)
		{
			ft_acc_width(data, bf);
			return (1);
		}
		else
		{
			ft_add_sign(data, bf);
			ft_fill_zeroes_di(data, bf);
			ft_fill_bf(data, bf);
			return (1);
		}
	}
	return (0);
}

void ft_print_di(t_printf *data, t_buffer *bf)
{
	if (_ft_width_acc(data, bf))
		return ;
	if (data->flags & FLAG_SPACE && !data->width)
		data->width = data->len + 1;
	if (data->width > data->len && bf->temp[0] != '0')
	{
		ft_width(data, bf);
		return;
	}
	if (bf->temp[0] == '0' && data->acc && !data->accuracy)
	{
		bf->temp[0] = ' ';
		if (data->width > data->len)
			ft_width(data, bf);
		return;
	}
	ft_add_sign(data, bf);
	ft_fill_bf(data, bf);
}
