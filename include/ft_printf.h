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
typedef enum
{
	false,
	true
}		bool;

typedef struct	s_printf
{
	char		type;
	char		flags;
	unsigned	width;
	unsigned	accuracy;
	char		size;
	bool		sign;
	unsigned	len;
	bool		acc;
	unsigned	l_count;
	unsigned	h_count;
	unsigned	printed;
}				t_printf;

typedef struct	s_buffer
{
	unsigned	s;
	char		temp[20];
	char		buffer[512];
}				t_buffer;

int				ft_printf(cc *format, ...);
cc				*ft_check_ptc(va_list ap, cc *format, t_printf *data, t_buffer *bf);
int				ft_specifier_format(cc *format, t_printf *data);
void			ft_choose_print(va_list ap, cc *format, t_printf *data, t_buffer *bf);
void			ft_dioux_x(va_list ap, cc *format, t_printf *data, t_buffer *bf);
void			ft_print_di(t_printf *data, t_buffer *bf);
void			ft_print_oux_x(t_printf *data, t_buffer *bf);
void			ft_print_char(va_list ap, t_printf *data, t_buffer *bf);
void			ft_print_string(va_list ap, t_printf *data, t_buffer *bf);
void			ft_print_percent(t_printf *data, t_buffer *bf);

/* Support functions */
int				type(char c);
void			ft_itoa_base(ulli value, int base, t_printf *data, t_buffer *bf);
void			ft_check_buffer(t_printf *data, t_buffer *bf);
void			ft_fill_bf(t_printf *data, t_buffer *bf);
void			ft_fill_spaces_oux(t_printf *data, t_buffer *bf);
void			ft_fill_zeroes_oux(t_printf *data, t_buffer *bf);

#endif
