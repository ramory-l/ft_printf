#ifndef FT_PRINT_F_H
#define FT_PRINT_F_H

#include "get_next_line.h"
#include <stdarg.h>
#include <stdio.h>

# define INIT 0
# define FLAG_MINUS (1 << 1)
# define FLAG_PLUS (1 << 2)
# define FLAG_SPACE (1 << 3)
# define FLAG_OCT (1 << 4)
# define FLAG_ZERO (1 << 5)

int				ft_printf(const char *format, ...);
const char		*ft_manage_percent(const char *format, va_list ap);
void			ft_print_signed_num(long long int number);
char			*ft_itoa_signed(long long int number);
void			ft_print_unsigned_num(unsigned long long int number, char c);
char			*ft_itoa_base_unsigned(unsigned long long int number, int base);

#endif