#include "ft_printf.h"

void		ft_manage_di(t_printf *data)
{
	char buffer[512];

	ft_bzero(buffer, sizeof(buffer));
	ft_fill_buff(0, buffer, data->nbr);
	if (ft_strcmp(data->nbr, "0") != 0)
		free(data->nbr);
	write(1, buffer, data->len);
	data->printed += data->len;
}