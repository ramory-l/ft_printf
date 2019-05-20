#include "ft_printf.h"

static void		ft_manage_flags(t_printf *data)
{
	if (data->flags & FLAG_MINUS && data->flags & FLAG_ZERO)
		data->flags &= ~FLAG_ZERO;
	if (data->flags & FLAG_PLUS && data->flags & FLAG_SPACE)
		data->flags &= ~FLAG_SPACE;
	if (data->flags & FLAG_ZERO && data->accuracy > 0)
		data->flags &= ~FLAG_ZERO;
}

const char	*ft_check_ptc(va_list ap, const char *format, t_printf *data)
{
	int type_index;

	type_index = ft_specifier_format(format, data);
	if (type_index == 0)
		return ("");
	ft_manage_flags(data);
	ft_choose_print(ap, format, data);
	return (format + type_index + 1);
}
