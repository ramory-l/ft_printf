#include "ft_printf.h"

static void	ft_width_accuracy(char *buffer, t_printf *data)
{
	int	turn;

	turn = 0;
	if (!(data->flags & FLAG_MINUS) && data->width > data->len &&
		!(data->flags & FLAG_ZERO) && !(data->flags & FLAG_OCT))
		turn = ft_fill_spaces(buffer, '<', data->width, data->len);
	if (data->flags & FLAG_MINUS && data->width > data->len &&
		!(data->flags & FLAG_OCT))
		turn = ft_fill_spaces(buffer, '>', data->width, data->len);
	if (data->flags & FLAG_ZERO && data->width > data->len &&
		!(data->flags & FLAG_OCT))
		turn = ft_fill_zeroes(buffer, '<', data->width, data->len);
	if (data->flags & FLAG_ZERO && data->width > data->len &&
		data->flags & FLAG_OCT)
	{
		data->width -= 2;
		turn = ft_fill_zeroes(buffer, '<', data->width, data->len);
	}
	if (turn)
		data->len = data->width;
}

static void	ft_oct(char *buffer, t_printf *data)
{
	int turn;

	turn = 0;
	if (data->type == 'x')
		data->temp = "0x";
	if (data->type == 'X')
		data->temp = "0X";
	if (data->flags & FLAG_OCT)
	{
		ft_move_buff(buffer, 2);
		buffer[0] = data->temp[0];
		buffer[1] = data->temp[1];
		data->len += 2;
		if (data->width > data->len && !(data->flags & FLAG_MINUS))
			turn = ft_fill_spaces(buffer, '<', data->width, data->len);
		if (data->width > data->len && data->flags & FLAG_MINUS)
			turn = ft_fill_spaces(buffer, '>', data->width, data->len);
		if (turn)
			data->len = data->width;
	}
}

static int	ft_check_zero(char *buffer, t_printf *data)
{
	if (data->nbr[0] == '0')
	{
		if (data->acc && !data->accuracy)
		{
			buffer[data->len] = '\0';
			write(1, buffer, data->len);
		}
		else
		{
			data->len++;
			write(1, buffer, data->len);
		}
		data->printed += data->len;
		return (1);
	}
	return (0);
}

void		ft_manage_oux_x(t_printf *data)
{
	char buffer[512];

	ft_bzero(buffer, sizeof(buffer));
	ft_fill_buff(0, buffer, data->nbr);
	ft_width_accuracy(buffer, data);
	if (ft_check_zero(buffer, data))
	{
		data->len = 0;
		return ;
	}
	ft_oct(buffer, data);
	write(1, buffer, data->len);
	data->printed += data->len;
	if (data->nbr[0] != '0')
		free(data->nbr);
}