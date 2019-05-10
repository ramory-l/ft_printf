#ifndef FT_PRINT_F_H
#define FT_PRINT_F_H

#include "get_next_line.h"
#include <stdarg.h>

# define INIT 0
# define FLAG_MINUS 1
# define FLAG_PLUS 2
# define FLAG_SPACE 4
# define FLAG_OCT 8
# define FLAG_ZERO 16

typedef struct	s_printf
{
	char	type;
	char	flags;
	int		width;
	int		accuracy;
	char	*size;
	int		printed;
}				t_printf;

int				ft_printf(const char *format, ...);
const char		*ft_manage_percentage(va_list ap, const char *format, t_printf *data);
void			ft_print(va_list ap, const char *format, t_printf *data);
char			*ft_itoa_signed(long long int value);
char			*ft_itoa_base_unsigned(unsigned long long int value, int base);

#endif