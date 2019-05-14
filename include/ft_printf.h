#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "get_next_line.h"
# include <stdarg.h>

# define INIT 0
# define FLAG_MINUS 1
# define FLAG_PLUS 2
# define FLAG_SPACE 4
# define FLAG_OCT 8
# define FLAG_ZERO 16

typedef struct	s_sup
{
	int			i;
	const char	*temp;
	va_list		ap;
}				t_sup;

typedef struct	s_printf
{
	char	type;
	char	flags;
	int		width;
	int		accuracy;
	char	*size;
	char	*nbr;
	int		printed;
	t_sup	sup;
}				t_printf;

int				ft_printf(const char *format, ...);
const char		*ft_percentage(va_list ap, const char *format, t_printf *data);
char			ft_find_flags(const char *format, int type_index);
char			*ft_find_size(const char *format, int type_index);
int				ft_find_width(const char *format, int type_index);
int				ft_find_accuracy(const char *format, int type_index);
void			ft_manage_signed(t_printf *data);
void			ft_manage_unsigned(t_printf *data);
void			ft_print(va_list ap, const char *format, t_printf *data);
char			*ft_itoa_signed(long long int value);
char			*ft_itoa_base_unsigned(unsigned long long int value, int base);

#endif
