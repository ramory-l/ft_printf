#include "ft_printf.h"

static void	ft_accuracy(t_printf *data, t_buffer *bf)
{
	int i;

	i = data->len;
	if (data->type == 'o' && data->accuracy > data->len)
	{
		while (i < data->accuracy)
		{
			bf->buffer[bf->s] = '0';
			bf->s++;
			i++;
			ft_check_buffer(data, bf);
		}
	}
}

static void ft_oct(t_printf *data, t_buffer *bf)
{
	char *temp;

	if (data->flags & FLAG_OCT && !data->acc)
	{
		if (data->type == 'x' || data->type == 'X')
		{
			if (data->type == 'x')
				temp = "0x";
			if (data->type == 'X')
				temp = "0X";
			bf->buffer[bf->s] = temp[0];
			bf->buffer[bf->s + 1] = temp[1];
			bf->s += 2;
		}
		else if (data->type == 'o')
		{
			temp = "0";
			bf->buffer[bf->s] = temp[0];
			bf->s++;
		}
	}
}

static int ft_width(t_printf *data, t_buffer *bf)
{
	ft_accuracy(data, bf);
	if (data->width > data->len && !(data->flags & FLAG_ZERO) &&
		!(data->flags & FLAG_MINUS))
	{
		ft_fill_spaces_oux(data, bf);
		ft_oct(data, bf);
	}
	if (data->width > data->len && data->flags & FLAG_ZERO)
	{
		ft_oct(data, bf);
		ft_fill_zeroes_oux(data, bf);
	}
	if (data->width > data->len && data->flags & FLAG_MINUS)
	{
		ft_oct(data, bf);
		ft_fill_bf(data, bf);
		ft_fill_spaces_oux(data, bf);
		return (1);
	}
	if (!data->width)
		ft_oct(data, bf);
	return (0);
}

void ft_print_oux_x(t_printf *data, t_buffer *bf)
{
	if (bf->temp[0] == '0')
	{
		if (data->acc && data->type == 'o' && data->flags & FLAG_OCT)
		{
			ft_fill_bf(data, bf);
			return ;
		}
		if (!data->acc)
		{
			ft_fill_bf(data, bf);
			return ;
		}
		else
		{
			bf->temp[0] = '\0';
			data->len = 0;
		}
	}
	if (ft_width(data, bf))
		return;
	ft_fill_bf(data, bf);
}