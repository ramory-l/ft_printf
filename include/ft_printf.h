#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "get_next_line.h"
# include <stdarg.h>

# define FLAG_MINUS 1
# define FLAG_PLUS 2
# define FLAG_SPACE 4
# define FLAG_OCT 8
# define FLAG_ZERO 16

# define SIZE_LL 1
# define SIZE_L 2
# define SIZE_H 4
# define SIZE_HH 8

typedef unsigned long long int ulli;
typedef long long int lli;
typedef const char cc;

typedef struct	s_printf
{
	char		type;
	char		flags;
	int			width;
	int			accuracy;
	char		size;
	char		*nbr;
	int			printed;
	int			sign;
	int			len;
	int			acc;
	char		*temp;
	int			l_count;
	int			h_count;
}				t_printf;

typedef struct	s_buffer
{
	unsigned	s;
	char		buffer[512];
}				t_buffer;

int				ft_printf(cc *format, ...);
cc				*ft_check_ptc(va_list ap, cc *format, t_printf *data, t_buffer *bf);
int				ft_specifier_format(cc *format, t_printf *data);
void			ft_choose_print(va_list ap, cc *format, t_printf *data, t_buffer *bf);
void			ft_manage_di(t_printf *data);
void			ft_manage_oux_x(t_printf *data);
void			ft_minus_width_rule(t_printf *data);
void			ft_dioux_x(va_list ap, cc *format, t_printf *data, t_buffer *bf);
void			ft_itoa_signed(lli value, t_buffer *bf);
char			*ft_itoa_base_unsigned(ulli value, int base, t_printf *data);

#endif
