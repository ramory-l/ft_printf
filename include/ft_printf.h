#ifndef FT_PRINT_F_H
#define FT_PRINT_F_H

#include "get_next_line.h"
#include <stdarg.h>
#include <stdio.h>

# define INIT 0
# define FLAG_MINUS (1 << 1)
# define FLAG_PLUS (1 << 2)
# define FLAG_ZERO (1 << 3)
# define FLAG_SPACE (1 << 4)
# define FLAG_OCT (1 << 5)

int		ft_printf(const char *format, ...);
void	ft_manage_percent(const char *format, va_list ap);
int		ft_print_number(unsigned long long int number, char c);

#endif