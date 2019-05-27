#include "ft_printf.h"

static void	ft_width_accuracy(char *buffer, t_printf *data)
{
	int turn;

	turn = 0;
	if (data->flags & FLAG_SPACE && buffer[0] != '-')
	{
		ft_fill_spaces(buffer, '<', data->len + 1, data->len);
		data->len++;
	}
	if (data->width > data->len)
		turn = ft_fill_spaces(buffer, '<', data->width, data->len);
	if (turn)
		data->len = data->width;
}

void		ft_manage_di(t_printf *data)
{
	char buffer[512];

	ft_bzero(buffer, sizeof(buffer));
	ft_fill_buff(0, buffer, data->nbr);
	ft_width_accuracy(buffer, data);
	if (ft_strcmp(data->nbr, "0") != 0)
		free(data->nbr);
	write(1, buffer, data->len);
	data->printed += data->len;
}