#include "ft_printf.h"

static void	ft_width_accuracy(char *buffer, t_printf *data)
{
	if (!(data->flags & FLAG_MINUS) && data->width > data->len &&
		!(data->flags & FLAG_ZERO))
		ft_fill_spaces(buffer, '<', data->nbr, data->width);
	if (data->flags & FLAG_MINUS && data->width > data->len)
		ft_fill_spaces(buffer, '>', data->nbr, data->width);
	if (data->flags & FLAG_ZERO && data->width > data->len &&
		!(data->flags & FLAG_OCT))
		ft_fill_zeroes(buffer, '<', data->nbr, data->width);
	if (data->flags & FLAG_ZERO && data->width > data->len &&
		data->flags & FLAG_OCT)
	{
		data->width -= 2;
		ft_fill_zeroes(buffer, '<', data->nbr, data->width);
	}
	data->len += data->width - data->len;
}

static void	ft_oct(char *buffer, t_printf *data)
{
	int		i;
	char	*temp;

	i = 0;
	temp = ft_strdup(buffer);
	if (data->type == 'x')
		data->temp = "0x";
	if (data->type == 'X')
		data->temp = "0X";
	if (data->flags & FLAG_OCT)
	{
		while (data->temp[i])
		{
			buffer[i] = data->temp[i];
			i++;
		}
		ft_fill_buff(i, buffer, temp);
		data->len += 2;
	}
	free(temp);
}

void		ft_manage_oux_x(t_printf *data)
{
	char buffer[512];

	ft_bzero(buffer, sizeof(buffer));
	ft_fill_buff(0, buffer, data->nbr);
	ft_width_accuracy(buffer, data);
	ft_oct(buffer, data);
	write(1, buffer, data->len);
	data->printed += data->len;
	if (ft_strcmp(data->nbr, "0") != 0)
		free(data->nbr);
}